#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <string>

using namespace std;

class Login
{
private:
  string archvio = "login.csv";

public:
  Login();
  bool esAutorizado(string usuario, string password, string &usuarioActual);
  string getArchvio() const;
};

#endif // LOGIN_H
