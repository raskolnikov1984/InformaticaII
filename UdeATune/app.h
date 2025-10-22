#ifndef APP_H_
#define APP_H_

#include <iostream>
#include <string>
#include <unistd.h>

#include "estructuras_datos/lista_dinamica.h"
#include "storage.h"
#include "cancion.h"
#include "login.h"

using namespace std;

class App {

public:
  App();
  explicit App(const string &ruta_almacenamiento);

  ~App();

  string usuarioActual = "";
  string tipoMembresia = "";
  bool enEjecusion = false;
  Storage *storage;
  ListaDinamica<Cancion> canciones;

  bool iniciarSesion(const string& usuario, const string& password);
  bool verificarRuta(string& ruta);
  bool setAlmacenamiento(string ruta_almacenamiento);
  int imprimirMenu(const string &menu, int opcion_inicial, int opcion_final);
  void imprimirBarra();
  void run();

  string getAlmacenamiento() const;
  bool getReproduccionAleatoria() const;
  void setReproduccionAleatoria(bool newReproduccionAleatoria);

  void mostrarCancionesCargadas() const {
    cout << "=== CANCIONES CARGADAS ===" << endl;
    cout << "Total: " << canciones.obtenerTamaño() << " canciones" << endl;

    for (size_t i = 0; i < canciones.obtenerTamaño(); i++) {
      cout << i+1 << ". " << canciones[i].getIdentificador() << " | " << canciones[i].getNombre() << " - " << canciones[i].getAlbum() << endl;
    }
    cout << "==========================" << endl;
  }

private:
  string almacenamiento;
  bool reproduccionAleatoria;


protected:


};

#endif // APP_H_
