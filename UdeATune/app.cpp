#include "app.h"
#include <limits>
#include <stdexcept>

string menu_standard = "1. Reproducción Aleatoria\n2. Salir\n";
string menu_premium = "1. Reproducción Aleatoria\n2. Mi Lista de Favoritos\n3. Salir";
string menu_lista_favoritos = "1. Editar mi lista de favoritos\n2. Seguir otra lista de favoritos\n3. Ejecutar mi lista de favoritos\n4. Volver al menú principal\n";


App::App() : almacenamiento("") {

};

App::App(const string &ruta_almacenamiento) {
  if (!setAlmacenamiento(ruta_almacenamiento)) {
        throw runtime_error("No se pudo inicializar con la ruta: " + ruta_almacenamiento);
    }
}

int App::imprimirMenu(const string &menu, int opcion_inicial, int opcion_final) {
    int opcion = 0;
    bool entrada_valida = false;

    do {
        cout << menu << endl;
        cout << "Por favor ingrese una opción (" << opcion_inicial << " - " << opcion_final << "): ";

        if (cin >> opcion) {
            if (opcion >= opcion_inicial && opcion <= opcion_final) {
                entrada_valida = true;
            } else {
                cout << "❌ Error: opción fuera de rango. Intente nuevamente.\n";
            }
        } else {
            cout << "❌ Error: debe ingresar un número.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (!entrada_valida);

    return opcion;
}

void App::imprimirBarra() {
  cout << "| Usuario: " << this->usuarioActual << " | Tipo Membresia: " << this->tipoMembresia << " |"<< endl;

};

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
  if (!Login().esAutorizado(usuario, password, this->usuarioActual, this->tipoMembresia)) {
    return false;
  }
  this->enEjecusion = true;
  return true;
};

void App::run() {

  //1. Iniciar Sesion
  string usuario;
  string password;

  int opcion = 0;

  cout << "Por Favor ingresa tu usuario: " << endl;
  cin >> usuario;
  cout << "Por Favor ingresa tu password: " << endl;
  cin >> password;

  iniciarSesion(usuario, password);

  if (this->enEjecusion) {
    cout << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "@@         Bienvenido A UdeATune,    "<< usuario << "!     @@" << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << endl;

    while (this->enEjecusion) {
      imprimirBarra();
      cout << endl;
      if (this->tipoMembresia == "estandar") {
        opcion = imprimirMenu(menu_standard, 1, 2);

        switch (opcion) {
        case 1:
          cout << "Opcion 1" << endl;
          break;
        case 2:
          enEjecusion = false;
          break;
        default:
          cerr << "Opcion No Valida" << endl;
        }

      } else if (this->tipoMembresia == "premium") {
        imprimirMenu(menu_premium, 1, 3);
        switch (opcion) {
        case 1:
          cout << "Opcion 1" << endl;
          break;
        case 2:
          cout <<  "Opcion 2" << endl;
          break;
        case 3:
          enEjecusion = false;
          break;
        default:
          cerr << "Opcion No Valida" << endl;
        }

      } else {
        cerr << "No cuenta con un membresia" << endl;
        enEjecusion = false;
      }
    };

  } else {
    cout << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "@@    Verifique Sus Credenciales!   @@" << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << endl;
  }

}
