#ifndef APP_H_
#define APP_H_

#include <iostream>
#include <random>
#include <string>
#include <unistd.h>

#include "estructuras_datos/lista_dinamica.h"
#include "storage.h"
#include "cancion.h"
#include "anuncio.h"
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
  int aleatorioActual;
  ListaDinamica<Cancion> canciones;
  ListaDinamica<Anuncio> anuncios;

  string getAlmacenamiento() const;
  bool setAlmacenamiento(string ruta_almacenamiento);
  bool getReproduccionAleatoria() const;
  void setReproduccionAleatoria(bool newReproduccionAleatoria);

  bool iniciarSesion(const string& usuario, const string& password);
  bool verificarRuta(string &ruta);
  int generarPseudoAleatorio(int ultimoNumero);

  void mostrarCancionesCargadas() const;
  int imprimirMenu(const string &menu, int opcion_inicial, int opcion_final);
  void imprimirBarra();

  void run();

private:
  string almacenamiento;
  bool reproduccionAleatoria;


protected:


};

#endif // APP_H_
