#include "app.h"
#include <limits>
#include <stdexcept>

string menu_standard = "1. Reproducción Aleatoria\n2. Salir\n";
string menu_premium = "1. Reproducción Aleatoria\n2. Mi Lista de Favoritos\n3. Salir";
string menu_lista_favoritos = "1. Editar mi lista de favoritos\n2. Seguir otra lista de favoritos\n3. Ejecutar mi lista de favoritos\n4. Volver al menú principal\n";


App::App() : almacenamiento(" "), usuarioActual(""), tipoMembresia(""),
             enEjecusion(false), reproduccionAleatoria(false) {
    this->storage = new Storage();
};

App::App(const string &ruta_almacenamiento)
    : usuarioActual(""), tipoMembresia(""), enEjecusion(false),
      reproduccionAleatoria(false) {

    if (!setAlmacenamiento(ruta_almacenamiento)) {
        throw runtime_error("No se pudo inicializar con la ruta: " + ruta_almacenamiento);
    }
    this->storage = new Storage();

    string almacenamiento_canciones =
        ruta_almacenamiento + "/data/canciones.csv";
    string almacenamiento_anuncios = ruta_almacenamiento + "/data/publicidad.csv";
    storage->cargarCanciones(almacenamiento_canciones, canciones);
    storage->cargarAnuncios(almacenamiento_anuncios, anuncios);
}


App::~App() {
  delete storage;
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

int App::generarPseudoAleatorio(int ultimoNumero) {
  random_device r;

  default_random_engine e1(r());
  uniform_int_distribution<int> uniform_dist(0, ultimoNumero);

  int mean = uniform_dist(e1);

  return mean;
};

void App::mostrarCancionesCargadas() const {
  cout << "=== CANCIONES CARGADAS ===" << endl;
  cout << "###########################################################" << endl;
  cout << "Total: " << canciones.obtenerTamaño() << " canciones" << endl;

  for (size_t i = 0; i < canciones.obtenerTamaño(); i++) {
    cout << "==========================================================" << endl;
    cout << i + 1 << ". " << canciones[i].getIdentificador() << " | "
    << canciones[i].getNombre() << " - " << canciones[i].getAlbum()
    << endl;
    cout << "==========================================================" << endl;
  }
  cout << "###########################################################" << endl;
}

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

void App::reproducirAleatoriamente() {
  bool seguirReproduciendo = true;
  while (seguirReproduciendo && this->enEjecusion) {
    aleatorioActual = generarPseudoAleatorio(canciones.obtenerTamaño());
    this->canciones[aleatorioActual].imprimirInformacion();

    cout << endl;
    cout << "¿Desea reproducir otra canción? (1 = Sí, 0 = No): ";
    int continuar;
    cin >> continuar;

    if (continuar != 1) {
      seguirReproduciendo = false;
    }
    cout << endl;
  };
}

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

    cout << "Almacenamiento: " << this->almacenamiento << endl;
    cout << endl;
    mostrarCancionesCargadas();

    while (this->enEjecusion) {
      cout << endl;
      imprimirBarra();
      cout << endl;

      if (this->tipoMembresia == "estandar") {
        opcion = imprimirMenu(menu_standard, 1, 2);
        setReproduccionAleatoria(true);

        switch (opcion) {
        case 1:
          reproducirAleatoriamente();
          break;
        case 2:
          enEjecusion = false;
          break;
        default:
          cerr << "Opcion No Valida" << endl;
        }

      } else if (this->tipoMembresia == "premium") {
        setReproduccionAleatoria(false);

        cout << getReproduccionAleatoria() << endl;
        imprimirMenu(menu_premium, 1, 3);
        switch (opcion) {
        case 1:
          reproducirAleatoriamente();
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

string App::getAlmacenamiento() const
{
    return almacenamiento;
}

bool App::getReproduccionAleatoria() const
{
    return this->reproduccionAleatoria;
}

void App::setReproduccionAleatoria(bool newReproduccionAleatoria)
{
    reproduccionAleatoria = newReproduccionAleatoria;
}
