#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "methods.h"

using namespace std;

struct User {
    char cedula[20];
    char clave[50];
    double saldo;
};

class BankingSystem {
private:
    const char* ADMIN_FILE = "sudo.txt";
    const char* USERS_FILE = "users.dat";
    const int TRANSACTION_COST = 1000;
    const int ENCRYPTION_SEED = 8;
    const int ENCRYPTION_METHOD = 1;
    const int MAX_USERS = 100;

public:
    // Función para encriptar texto usando los métodos ya implementados
    string encryptText(const char* text) {
        int len = strlen(text);
        string binary = textToBinary(text, len);
        return encodeMethod1(binary, ENCRYPTION_SEED);
    }

    // Función para desencriptar texto
    string decryptText(const string& encryptedBinary) {
        string decryptedBinary = decodeMethod1(encryptedBinary, ENCRYPTION_SEED);
        return binaryToText(decryptedBinary);
    }

    // Crear archivo de administrador por primera vez
    void createAdminFile() {
        ofstream file(ADMIN_FILE);
        if (file.is_open()) {
            const char* adminPassword = "admin123";
            string encryptedPassword = encryptText(adminPassword);

            // Guardar como archivo binario
            const char* tempFile = "temp_admin.dat";
            writeBinaryFile(encryptedPassword, tempFile);

            // Leer el archivo binario y guardarlo en sudo.txt
            ifstream temp(tempFile, ios::binary);
            ofstream admin(ADMIN_FILE, ios::binary);
            admin << temp.rdbuf();
            temp.close();
            admin.close();

            remove(tempFile);
            cout << "Archivo de administrador creado. Contraseña: admin123\n";
        }
    }

    // Validar acceso de administrador
    bool validateAdmin() {
        ifstream file(ADMIN_FILE, ios::binary);
        if (!file.is_open()) {
            cout << "Archivo de administrador no encontrado. Creando uno nuevo...\n";
            createAdminFile();
            return validateAdmin();
        }

        // Leer la contraseña encriptada
        string encryptedBinary = readBinaryFile(ADMIN_FILE);
        if (encryptedBinary.empty()) {
            cout << "Error al leer el archivo de administrador.\n";
            return false;
        }

        string storedPassword = decryptText(encryptedBinary);

        char inputPassword[100];
        cout << "Ingrese la contraseña de administrador: ";
        cin >> inputPassword;

        return strcmp(inputPassword, storedPassword.c_str()) == 0;
    }

    // Contar usuarios en el arreglo
    int countUsers(User* users) {
        int count = 0;
        for (int i = 0; i < MAX_USERS; i++) {
            if (strlen(users[i].cedula) > 0) {
                count++;
            }
        }
        return count;
    }

    // Buscar usuario por cédula en el arreglo
    User* findUser(User* users, const char* cedula) {
        for (int i = 0; i < MAX_USERS; i++) {
            if (strcmp(users[i].cedula, cedula) == 0) {
                return &users[i];
            }
        }
        return nullptr;
    }

    // Agregar usuario al arreglo
    bool addUser(User* users, const User& newUser) {
        for (int i = 0; i < MAX_USERS; i++) {
            if (strlen(users[i].cedula) == 0) {
                strcpy(users[i].cedula, newUser.cedula);
                strcpy(users[i].clave, newUser.clave);
                users[i].saldo = newUser.saldo;
                return true;
            }
        }
        return false; // Arreglo lleno
    }

    // Cargar usuarios desde archivo encriptado
    void loadUsers(User* users) {
        // Inicializar arreglo
        for (int i = 0; i < MAX_USERS; i++) {
            users[i].cedula[0] = '\0';
            users[i].clave[0] = '\0';
            users[i].saldo = 0.0;
        }

        ifstream file(USERS_FILE, ios::binary);
        if (!file.is_open()) {
            return; // Archivo no existe
        }

        string encryptedBinary = readBinaryFile(USERS_FILE);
        if (encryptedBinary.empty()) {
            return;
        }

        string decryptedData = decryptText(encryptedBinary);

        // Parsear manualmente sin stringstream para cada línea
        char* data = new char[decryptedData.length() + 1];
        strcpy(data, decryptedData.c_str());

        char* line = strtok(data, "\n");
        int userIndex = 0;

        while (line != nullptr && userIndex < MAX_USERS) {
            if (strlen(line) > 0) {
                // Parsear línea: cedula|clave|saldo
                char* cedula = strtok(line, "|");
                char* clave = strtok(nullptr, "|");
                char* saldoStr = strtok(nullptr, "|");

                if (cedula && clave && saldoStr) {
                    strcpy(users[userIndex].cedula, cedula);
                    strcpy(users[userIndex].clave, clave);
                    users[userIndex].saldo = atof(saldoStr);
                    userIndex++;
                }
            }
            line = strtok(nullptr, "\n");
        }

        delete[] data;
    }

    // Guardar usuarios en archivo encriptado
    void saveUsers(User* users) {
        // Crear string con todos los datos
        char* userData = new char[10000]; // Buffer grande
        userData[0] = '\0';

        for (int i = 0; i < MAX_USERS; i++) {
            if (strlen(users[i].cedula) > 0) {
                char userLine[200];
                sprintf(userLine, "%s|%s|%.2f\n",
                        users[i].cedula, users[i].clave, users[i].saldo);
                strcat(userData, userLine);
            }
        }

        string encryptedBinary = encryptText(userData);
        writeBinaryFile(encryptedBinary, USERS_FILE);

        delete[] userData;
    }

    // Registrar nuevo usuario
    void registerUser() {
        User* users = new User[MAX_USERS];
        loadUsers(users);

        User newUser;
        cout << "=== REGISTRO DE NUEVO USUARIO ===\n";
        cout << "Cédula: ";
        cin >> newUser.cedula;
        cout << "Clave: ";
        cin >> newUser.clave;
        cout << "Saldo inicial (COP): ";
        cin >> newUser.saldo;

        // Verificar si el usuario ya existe
        if (findUser(users, newUser.cedula) != nullptr) {
            cout << "Error: Usuario con esa cédula ya existe.\n";
            delete[] users;
            return;
        }

        if (addUser(users, newUser)) {
            saveUsers(users);
            cout << "Usuario registrado exitosamente.\n";
        } else {
            cout << "Error: No se pueden registrar más usuarios.\n";
        }

        delete[] users;
    }

    // Validar acceso de usuario
    User* validateUser(User* users) {
        char cedula[20], clave[50];
        cout << "Cédula: ";
        cin >> cedula;
        cout << "Clave: ";
        cin >> clave;

        User* user = findUser(users, cedula);
        if (user && strcmp(user->clave, clave) == 0) {
            return user;
        }
        return nullptr;
    }

    // Consultar saldo
    void consultBalance(User* user) {
        user->saldo -= TRANSACTION_COST;
        cout << "Costo de transacción: $" << TRANSACTION_COST << " COP\n";
        cout << "Su saldo actual es: $" << user->saldo << " COP\n";
    }

    // Retirar dinero
    void withdrawMoney(User* user) {
        double amount;
        cout << "Cantidad a retirar: ";
        cin >> amount;

        double totalCost = amount + TRANSACTION_COST;

        if (user->saldo >= totalCost) {
            user->saldo -= totalCost;
            cout << "Retiro exitoso!\n";
            cout << "Cantidad retirada: $" << amount << " COP\n";
            cout << "Costo de transacción: $" << TRANSACTION_COST << " COP\n";
            cout << "Saldo restante: $" << user->saldo << " COP\n";
        } else {
            cout << "Fondos insuficientes.\n";
            cout << "Saldo disponible: $" << user->saldo << " COP\n";
            cout << "Total requerido: $" << totalCost << " COP (incluyendo costo de transacción)\n";
        }
    }

    // Menú de usuario
    void userMenu() {
        User* users = new User[MAX_USERS];
        loadUsers(users);

        cout << "=== ACCESO DE USUARIO ===\n";
        User* currentUser = validateUser(users);

        if (!currentUser) {
            cout << "Credenciales inválidas.\n";
            delete[] users;
            return;
        }

        cout << "Bienvenido, " << currentUser->cedula << "!\n";

        int option;
        do {
            cout << "\n=== MENÚ USUARIO ===\n";
            cout << "1. Consultar saldo\n";
            cout << "2. Retirar dinero\n";
            cout << "3. Salir\n";
            cout << "Seleccione una opción: ";
            cin >> option;

            switch (option) {
            case 1:
                consultBalance(currentUser);
                saveUsers(users);
                break;
            case 2:
                withdrawMoney(currentUser);
                saveUsers(users);
                break;
            case 3:
                cout << "Gracias por usar nuestro cajero.\n";
                break;
            default:
                cout << "Opción inválida.\n";
            }
        } while (option != 3);

        delete[] users;
    }

    // Menú de administrador
    void adminMenu() {
        if (!validateAdmin()) {
            cout << "Acceso denegado.\n";
            return;
        }

        cout << "Acceso de administrador exitoso.\n";

        int option;
        do {
            cout << "\n=== MENÚ ADMINISTRADOR ===\n";
            cout << "1. Registrar nuevo usuario\n";
            cout << "2. Listar usuarios\n";
            cout << "3. Salir\n";
            cout << "Seleccione una opción: ";
            cin >> option;

            switch (option) {
            case 1:
                registerUser();
                break;
            case 2:
                listUsers();
                break;
            case 3:
                cout << "Saliendo del menú de administrador.\n";
                break;
            default:
                cout << "Opción inválida.\n";
            }
        } while (option != 3);
    }

    // Listar usuarios (solo para administrador)
    void listUsers() {
        User* users = new User[MAX_USERS];
        loadUsers(users);

        int userCount = countUsers(users);

        if (userCount == 0) {
            cout << "No hay usuarios registrados.\n";
            delete[] users;
            return;
        }

        cout << "\n=== LISTA DE USUARIOS ===\n";
        cout << "Cédula\t\tSaldo (COP)\n";
        cout << "------------------------\n";

        for (int i = 0; i < MAX_USERS; i++) {
            if (strlen(users[i].cedula) > 0) {
                cout << users[i].cedula << "\t\t$" << users[i].saldo << "\n";
            }
        }

        delete[] users;
    }

    // Menú principal del sistema bancario
    void mainBankingMenu() {
        int option;

        do {
            cout << "\n=== SISTEMA BANCARIO ===\n";
            cout << "1. Acceso de Administrador\n";
            cout << "2. Acceso de Usuario\n";
            cout << "3. Volver al menú principal\n";
            cout << "Seleccione una opción: ";
            cin >> option;

            switch (option) {
            case 1:
                adminMenu();
                break;
            case 2:
                userMenu();
                break;
            case 3:
                cout << "Regresando al menú principal...\n";
                break;
            default:
                cout << "Opción inválida.\n";
            }
        } while (option != 3);
    }
};

int main(int argc, char *argv[]) {
    BankingSystem bank;

    int mainOption;
    do {
        cout << "\n=== MENÚ PRINCIPAL ===\n";
        cout << "1. Codificar archivo\n";
        cout << "2. Decodificar archivo\n";
        cout << "3. Sistema Bancario\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> mainOption;

        switch (mainOption) {
        case 1: {
            char inputFile[100], outputFile[100];
            int n, method;

            cout << "Archivo de texto a codificar: ";
            cin >> inputFile;
            cout << "Archivo de salida binaria: ";
            cin >> outputFile;
            cout << "Semilla (n): ";
            cin >> n;
            cout << "Método (1 o 2): ";
            cin >> method;

            ifstream in(inputFile, ios::binary | ios::ate);
            if (!in) {
                cerr << "No se pudo abrir el archivo de entrada.\n";
                break;
            }

            int length = in.tellg();
            in.seekg(0);
            char* buffer = new char[length];
            in.read(buffer, length);
            in.close();

            string bin = textToBinary(buffer, length);
            delete[] buffer;

            string encoded;
            if (method == 1)
                encoded = encodeMethod1(bin, n);
            else if (method == 2)
                encoded = encodeMethod2(bin, n);
            else {
                cerr << "Método inválido.\n";
                break;
            }

            writeBinaryFile(encoded, outputFile);
            cout << "Archivo codificado correctamente.\n";
            break;
        }
        case 2: {
            char inputFile[100], outputFile[100];
            int n, method;

            cout << "Archivo binario a decodificar: ";
            cin >> inputFile;
            cout << "Archivo de salida de texto: ";
            cin >> outputFile;
            cout << "Semilla (n): ";
            cin >> n;
            cout << "Método usado para codificar (1 o 2): ";
            cin >> method;

            string encodedBin = readBinaryFile(inputFile);
            if (encodedBin.empty()) break;

            string decodedBin;
            if (method == 1)
                decodedBin = decodeMethod1(encodedBin, n);
            else if (method == 2)
                decodedBin = decodeMethod2(encodedBin, n);
            else {
                cerr << "Método inválido.\n";
                break;
            }

            string text = binaryToText(decodedBin);

            ofstream out(outputFile, ios::binary);
            if (!out) {
                cerr << "No se pudo crear el archivo de salida.\n";
                break;
            }

            out.write(text.c_str(), text.size());
            out.close();

            cout << "Archivo decodificado correctamente.\n";
            break;
        }
        case 3:
            bank.mainBankingMenu();
            break;
        case 4:
            cout << "¡Gracias por usar el sistema!\n";
            break;
        default:
            cout << "Opción inválida.\n";
        }
    } while (mainOption != 4);

    return 0;
}
