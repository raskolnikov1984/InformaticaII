#include "favorito.h"

Favorito::Favorito() {}

Favorito::Favorito(const std::string& usuario, const std::string& cancionId)
    : usuario(usuario), cancionId(cancionId) {}

string Favorito::getCancionId() {
  return cancionId;
}


void Favorito::setCancionId(const string &newCancionId) {
  cancionId = newCancionId;
};


string Favorito::getUsuario() {
  return usuario;
}

void Favorito::setUsuario(const string &newUsuario) {
  usuario = newUsuario;
}
