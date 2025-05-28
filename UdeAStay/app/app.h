#ifndef APP_H
#define APP_H

#include "../usuario.h"
#include "../anfitrion.h"
#include "../huesped.h"
#include "../alojamiento.h"
#include "../reserva.h"
#include "../db/db.h"
#include <string>


struct LoginStruct {
    string tipoUsuario;
    string numeroDocumento;

    bool operator==(const LoginStruct& other) const {
        return tipoUsuario == other.tipoUsuario &&
               numeroDocumento == other.numeroDocumento;
    }
};

struct ContextStructure {
    LoginStruct login;
};


using namespace std;

class App
{

public:
    ContextStructure contexStruct;

    DB* db_app;
    Usuario* usuarios;
    Anfitrion* anfitriones;
    Huesped* huespedes;
    Alojamiento* alojamientos;
    Reserva* reservas;

    App(const tablasStructure& tablasStruct);
    ~App();
    bool validate_user(const string& usuario, const string& password);
    int cargarUsuarios(const string& tabla);
    int cargarAnfitriones(const string& tabla);
    int cargarHuespedes(const string& tabla);
    int cargarAlojamientos(const string& tabla);
    int cargarReservas(const string& tabla);
    void mostrarMenuHuesped();
    void mostrarMenuAnfitrion();

    bool reservarAlojamiento();
    bool anularReservacion();
    bool consultarReservas();
    bool actualizarHistorico();

    int run();
};

#endif // APP_H
