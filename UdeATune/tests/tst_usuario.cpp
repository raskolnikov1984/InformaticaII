#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "../usuario.h"

TEST(Usuario, Usuario) {
  Usuario usuario;
  usuario.setnickName("Nicolas");
  usuario.settipoMembresia("estandar");
  usuario.setpais("brasil");
  usuario.setciudad("florianopolis");
  usuario.setfechaInscripcion("2020-03-02");
}
