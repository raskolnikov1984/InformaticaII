#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>

using namespace std;

class Usuario {
private:
  string nickName;
  string tipoMembresia;
  string pais;
  string ciudad;
  string fechaInscripcion;

public:
  Usuario();
  Usuario(string nick, string membresia, string pais, string ciudad, string fecha);

  string getnickName();
  string gettipoMembresia();
  string getpais();
  string getciudad();
  string getfechaInscripcion();

  void setnickName(string nickName);
  void settipoMembresia(string tipoMembresia);
  void setpais(string pais);
  void setciudad(string ciudad);
  void setfechaInscripcion(string fechaInscripcion);

  bool cambiarTipoDeMembresia();
};

#endif // USUARIO_H
