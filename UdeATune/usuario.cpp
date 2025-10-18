#include "usuario.h"

Usuario::Usuario()
    : nickName(""), tipoMembresia(""), pais(""), ciudad(""),
      fechaInscripcion("") {}


Usuario::Usuario(string nick, string membresia, string pais, string ciudad, string fecha)
    : nickName(nick), tipoMembresia(membresia), pais(pais), ciudad(ciudad), fechaInscripcion(fecha) {
}
void Usuario::setnickName(string nickName) {
  this->nickName = nickName;
};
void Usuario::settipoMembresia(string tipoMembresia) {
  this->tipoMembresia = tipoMembresia;
};
void Usuario::setpais(string pais) {
  this->pais = pais;
};
void Usuario::setciudad(string ciudad) {
  this->ciudad = ciudad;
};
void Usuario::setfechaInscripcion(string fechaInscripcion) {
  this->fechaInscripcion = fechaInscripcion;
};
