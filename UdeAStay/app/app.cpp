#include <fstream>
#include <sstream>

#include "app.h"
#include "../usuario.h"
#include "../alojamiento.h"
#include "../db/db.h"


using namespace std;

int MAX_NUMERO_USUARIOS = 100;
int MAX_NUMERO_ALOJAMIENTOS = 100;


App::App(const tablasStructure& tablasStruct){
    db_app = new DB(tablasStruct);
    db_app->inicializarBaseDeDatos();

    usuarios = new Usuario[MAX_NUMERO_USUARIOS];
    alojamientos = new Alojamiento[MAX_NUMERO_ALOJAMIENTOS];
};

App::~App(){
    delete db_app;
};

int App::run(){
    int opcion;
    string usuario;
    string password;

    cout << "Por favor ingrese su usuario" << endl;
    cin >> usuario;

    cout << "Por favor ingrese su password" << endl;
    cin >> password;

    if(validate_user(usuario, password)){
        if(contexStruct.login.tipoUsuario == "huesped"){
            do {
                mostrarMenuHuesped();
                cout << "Por favor ingrese una opcion: ";
                cin >> opcion;
                switch(opcion) {
                    case 1: reservarAlojamiento(); break;
                    case 2:
                        anularReservacion();
                        break;
                }
            } while(opcion != 3);
            cout << "Usted esta saliendo del Aplicativo UdeAStay..." << endl;
        } else if(contexStruct.login.tipoUsuario == "anfitrion"){
            do{
                mostrarMenuAnfitrion();
                cout << "Por favor ingrese una opcion: ";
                cin >> opcion;
                switch(opcion) {
                case 1:
                    consultarReservas();
                    break;
                case 2: actualizarHistorico(); break;
                case 3:
                    anularReservacion();
                    break;
                }
            } while(opcion != 4);
        } else {
            cerr << "Error: El usuario no cuenta con un Rol Valido ('huesped'/'anfitrion')"
                 << "actual" <<  contexStruct.login.tipoUsuario;
            return 0;
        }
    } else {
        cerr << "Error: El usuario no ha podido ser validado." << endl;
    }

    return 0;
};

bool App::validate_user(const string& usuario, const string& password){
    int cantidadUsuarios = cargarUsuarios(db_app->getTablas().usuarios);
    for(int i=0; i < cantidadUsuarios; i++){
        if(usuarios[i].getNumeroDocumento() == usuario && usuarios[i].getPassword() == password){
            LoginStruct login;
            login.tipoUsuario = usuarios[i].getTipoUsuario();
            login.numeroDocumento = usuarios[i].getNumeroDocumento();
            contexStruct.login = login;

            cout << "Login Success!!" << endl;

            return true;
        }
    }
    return false;
};

void App::mostrarMenuHuesped() {
    cout << "\n--- Menú Huésped ---\n";
    cout << "1. Reservar alojamiento\n";
    cout << "2. Anular reservación\n";
    cout << "3. Salir\n";
};

void App::mostrarMenuAnfitrion() {
    cout << "\n--- Menú Anfitrión ---\n";
    cout << "1. Consultar reservaciones\n";
    cout << "2. Actualizar histórico\n";
    cout << "3. Anular reservación\n";
    cout << "4. Salir\n";
};

int App::cargarUsuarios(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    string linea;
    int contador = 0;

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        return 0;
    }

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string tipoUsuario, numeroDocumento, password;

        getline(ss, tipoUsuario, ',');
        getline(ss, numeroDocumento, ',');
        getline(ss, password, ',');

        (usuarios+contador)->setTipoUsuario(tipoUsuario);
        (usuarios+contador)->setNumeroDocumento(numeroDocumento);
        (usuarios+contador)->setPassword(password);

        contador++;
    }

    archivo.close();
    return contador;
};

int App::cargarAnfitriones(const string& tabla){
    return 0;
};

int App::cargarHuespedes(const string& tabla){
    return 0;
};

int App::cargarAlojamientos(const string& nombreArchivo){
    ifstream archivo(nombreArchivo);
    string linea;
    int contador = 0;

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        return 0;
    }

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string nombre, codigoIdentificador, anfitrion, departamento, municipio, tipo, direccion;
        string precioPorNoche;

        getline(ss, nombre, ',');
        getline(ss, codigoIdentificador, ',');
        getline(ss, anfitrion, ',');
        getline(ss, departamento, ',');
        getline(ss, municipio, ',');
        getline(ss, tipo, ',');
        getline(ss, direccion, ',');
        getline(ss, precioPorNoche, ',');

        (alojamientos+contador)->setNombre(nombre);
        (alojamientos+contador)->setCodigoIdentificador(codigoIdentificador);
        (alojamientos+contador)->setAnfitrion(anfitrion);
        (alojamientos+contador)->setDepartamento(departamento);
        (alojamientos+contador)->setMunicipio(municipio);
        (alojamientos+contador)->setTipo(tipo);
        (alojamientos+contador)->setDireccion(direccion);
        (alojamientos+contador)->setPrecioPorNoche(stod(precioPorNoche));

        contador++;
    }

    archivo.close();
    return contador;
    return 0;
};

int App::cargarReservas(const string& nombreArchivo){
    ifstream archivo(nombreArchivo);
    string linea;
    int contador = 0;

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        return 0;
    }

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string duracion, codigoReserva, codigoAlojamiento, documentoHuesped;

        getline(ss, documentoHuesped, ',');

        if(documentoHuesped == contexStruct.login.numeroDocumento){
            getline(ss, duracion, ',');
            getline(ss, codigoReserva, ',');
            getline(ss, codigoAlojamiento, ',');

            Reserva* reserva = (reservas+contador);
            reserva->setDuracion(stoi(duracion));
            reserva->setCodigoReserva(codigoReserva);
            reserva->setDocumentoHuesped(documentoHuesped);
            reserva->setCodigoAlojamiento(codigoAlojamiento);

            contador++;
        };
    }

    archivo.close();
    return contador;
};

bool App::reservarAlojamiento()
{
    return true;
};


bool App::anularReservacion() {
    string codigoReservaObjetivo;

    cout << "Por favor ingrese el codigo de su reservacion"<<endl;
    cin >> codigoReservaObjetivo;

    ifstream archivoEntrada(db_app->getTablas().reservas);
    if (!archivoEntrada.is_open()) {
        std::cerr << "No se pudo abrir el archivo de entrada." << std::endl;
        return false;
    }

    ofstream archivoTemporal("temporal.csv");
    if (!archivoTemporal.is_open()) {
        std::cerr << "No se pudo crear el archivo temporal." << std::endl;
        archivoEntrada.close();
        return false;
    }

    string linea;
    bool esPrimeraLinea = true;

    while (getline(archivoEntrada, linea)) {
        if (esPrimeraLinea) {
            archivoTemporal << linea << '\n'; // escribe encabezado siempre
            esPrimeraLinea = false;
            continue;
        }

        // Extrae el campo "codigoReserva", que está en la posición 1 (índice 1, después de duración)
        size_t primeraComa = linea.find(',');
        if (primeraComa != string::npos) {
            size_t segundaComa = linea.find(',', primeraComa + 1);
            string codigoReserva = linea.substr(primeraComa + 1, segundaComa - primeraComa - 1);

            // Si no coincide con el que queremos eliminar, lo escribimos
            if (codigoReserva != codigoReservaObjetivo) {
                archivoTemporal << linea << '\n';
            }
        }
    }

    archivoEntrada.close();
    archivoTemporal.close();

    // Reemplazar archivo original
    remove(db_app->getTablas().reservas.c_str());
    rename("temporal.csv", db_app->getTablas().reservas.c_str());

    std::cout << "Línea con código de reserva \"" << codigoReservaObjetivo << "\" eliminada correctamente.\n";

    return true;
};

bool App::consultarReservas()
{
    int cantidadReservas = cargarReservas(db_app->getTablas().reservas);
    for(int i=0; i<cantidadReservas;i++){
        cout << "CodigoReserva" << reservas[i].getCodigoReserva()
             << "Alojamiento" << reservas[i].getCodigoAlojamiento()
             << "Fecha" << reservas[i].getFechaEntrada()
             << "Duracion" << reservas[i].getDuracion();
    }
    return true;
};

bool App::actualizarHistorico()
{
    return true;
};


