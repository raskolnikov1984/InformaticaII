#include "usuario.h"

Usuario::Usuario()
    : nickName(""), tipoMembresia(""), pais(""), ciudad(""),
      fechaInscripcion("") {}


Usuario::Usuario(string nick, string membresia, string pais, string ciudad, string fecha)
    : nickName(nick), tipoMembresia(membresia), pais(pais), ciudad(ciudad), fechaInscripcion(fecha) {
}

bool Usuario::cambiarTipoDeMembresia() {
  string tipoMembresiaActual = this->gettipoMembresia();
  if ( tipoMembresiaActual == "estandar") {
    this->settipoMembresia("premium");
  } else if (tipoMembresiaActual == "premium") {
    this->settipoMembresia("estandar");
  } else {
    cerr << "No fue posible cambiar el tipo de membresia" << endl;
    return false;
  }
  return true;
};
string Usuario::getnickName() {
  return this->nickName;
};
string Usuario::gettipoMembresia() {
  return this->tipoMembresia;
};
string Usuario::getpais() {
  return this->pais;
};
string Usuario::getciudad() {
  return this->ciudad;
};
string Usuario::getfechaInscripcion() {
  return this->fechaInscripcion;
};

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
