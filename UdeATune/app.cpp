#include "app.h"
#include <stdexcept>


App::App() : almacenamiento("") {

};

App::App(const string &ruta_almacenamiento) {
  if (!setAlmacenamiento(ruta_almacenamiento)) {
        // Si falla la verificación, lanza excepción
        throw runtime_error("No se pudo inicializar con la ruta: " + ruta_almacenamiento);
    }
}

bool App::verificarRuta(string &ruta) {
    return access(ruta.c_str(), F_OK) == 0;
};

bool App::setAlmacenamiento(string ruta_almacenamiento) {
  if (!verificarRuta(ruta_almacenamiento)) {
    throw runtime_error("No Se Encontro la Ruta del Almacenamiento");
    return false;
  }
  this->almacenamiento = ruta_almacenamiento;
  return true;
};

bool App::iniciarSesion(const string &usuario, const string &password) {
  if (!Login().esAutorizado(usuario, password, this->usuarioActual)) {
    return false;
  }
  this->enEjecusion = true;
  return true;
};

void App::run() {

  //1. Iniciar Sesion
  string usuario;
  string password;

  cout << "Por Favor ingresa tu usuario: " << endl;
  cin >> usuario;
  cout << "Por Favor ingresa tu password: " << endl;
  cin >> password;

  iniciarSesion(usuario, password);

  if (this->enEjecusion) {
    cout << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "@@    Bienvenido A UdeATune!  @@" << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << endl;

    while (this->enEjecusion) {

    };

  } else {
    cout << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "@@    Verifique Sus Credenciales!   @@" << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << endl;
  }

}
