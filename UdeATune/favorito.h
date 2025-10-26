#ifndef FAVORITO_H_
#define FAVORITO_H_

#include <string>

using namespace std;

class Favorito {

public:
  Favorito();
  Favorito(const string& usuario, const string& cancionId);

  string getUsuario();
  string getCancionId();
  void setUsuario(const string &newUsuario);
  void setCancionId(const string& newCancionId);

private:
  string usuario;
  string cancionId;

};

#endif // FAVORITO_H_
