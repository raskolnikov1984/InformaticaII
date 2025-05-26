#include <fstream>
#include <sstream>

#include "app.h"
#include "../usuario.h"
#include "../db/db.h"



using namespace std;

App::App(const tablasStructure& tablasStruct){
    db_app = new DB(tablasStruct);
    db_app->inicializarBaseDeDatos();

    usuarios = new Usuario[100];
}

App::~App(){
    delete db_app;
}


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
                    case 2: anularReservacion(); break;
                }
            } while(opcion != 3);
            cout << "Usted esta saliendo del Aplicativo UdeAStay..." << endl;
        } else if(contexStruct.login.tipoUsuario == "anfitrion"){
            do{
                mostrarMenuAnfitrion();
                cout << "Por favor ingrese una opcion: ";
                cin >> opcion;
                switch(opcion) {
                case 1: consultarReservas(); break;
                case 2: actualizarHistorico(); break;
                case 3: anularReservacion(); break;
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
}

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
}

void App::mostrarMenuHuesped() {
    cout << "\n--- Menú Huésped ---\n";
    cout << "1. Reservar alojamiento\n";
    cout << "2. Anular reservación\n";
    cout << "3. Salir\n";
}

void App::mostrarMenuAnfitrion() {
    cout << "\n--- Menú Anfitrión ---\n";
    cout << "1. Consultar reservaciones\n";
    cout << "2. Actualizar histórico\n";
    cout << "3. Anular reservación\n";
    cout << "4. Salir\n";
}

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
}

bool App::reservarAlojamiento()
{
    return true;
}

bool App::anularReservacion()
{
    return true;
}

bool App::consultarReservas()
{
    return true;
}

bool App::actualizarHistorico()
{
    return true;
}

int cargarAnfitriones(const string& tabla){
    return 0;
};

int cargarHuespedes(const string& tabla){
    return 0;
};

int cargarAlojamientos(const string& tabla){;
    return 0;
}

int cargarReservas(const string& tabla){
    return 0;
};
