#include "login.h"
#include "storage.h"
#include <fstream>
#include <sstream>
#include "estructuras.h"

string Login::getArchvio() const
{
  return archvio;
}

Login::Login() {}

bool Login::esAutorizado(string usuario, string password, string& usuarioActual) {
  stringstream ss;
  string campo;
  string linea;

  ifstream loginData;
  Storage storage;

  storage.leerArchivo(
                      "/home/aserrador/Desktop/04-UdeA/InformaticaII/UdeATune/data/" +
                      Login().getArchvio(),
                      loginData);

  getline(loginData, linea);
  while (getline(loginData, linea)) {
    stringstream ss(linea);
    getline(ss, campo, ',');
    if (usuario == campo) {
      getline(ss, campo, ',');
      if (password == campo) {
        usuarioActual = usuario;
        return true;
      }
    };
  }

  loginData.close();

  usuarioActual = "";
  return false;
}
