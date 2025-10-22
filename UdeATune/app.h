#ifndef APP_H_
#define APP_H_

#include <iostream>
#include <string>

#include <unistd.h>

#include "login.h"

using namespace std;

class App {

public:
  App();
  App(const string &ruta_almacenamiento);

  string usuarioActual = "";
  string tipoMembresia = "";
  bool enEjecusion = false;

  bool iniciarSesion(const string& usuario, const string& password);
  bool verificarRuta(string& ruta);
  bool setAlmacenamiento(string ruta_almacenamiento);
  int imprimirMenu(const string &menu, int opcion_inicial, int opcion_final);
  void imprimirBarra();
  void run();

private:
  string almacenamiento;

protected:


};

#endif // APP_H_
