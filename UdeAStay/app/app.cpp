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

bool App::validate_user(const string& usaurio, const string& password){
    return true;
}

// Implementación de los métodos de carga
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
