#ifndef USUARIO_H
#define USUARIO_H

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

  void setnickName(string nickName);
  void settipoMembresia(string tipoMembresia);
  void setpais(string pais);
  void setciudad(string ciudad);
  void setfechaInscripcion(string fechaInscripcion);

};

#endif // USUARIO_H
