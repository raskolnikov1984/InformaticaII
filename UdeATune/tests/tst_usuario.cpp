#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "../usuario.h"

class UdeATuneUsuario : public ::testing::Test {
public:
  Usuario admin;

  void SetUp() override {
    admin.setnickName("admin");
    admin.settipoMembresia("estandar");
    admin.setpais("brasil");
    admin.setciudad("florianopolis");
    admin.setfechaInscripcion("2020-03-02");
  }
};

TEST_F(UdeATuneUsuario, Usuario) {
  EXPECT_EQ(admin.getnickName(), "admin");
  EXPECT_EQ(admin.gettipoMembresia(), "estandar");
  EXPECT_EQ(admin.getpais(), "brasil");
  EXPECT_EQ(admin.getciudad(), "florianopolis");
  EXPECT_EQ(admin.getfechaInscripcion(), "2020-03-02");
}

TEST_F(UdeATuneUsuario, CambiarTipoMembresia) {
  EXPECT_EQ(admin.cambiarTipoDeMembresia(), true);
  EXPECT_EQ(admin.gettipoMembresia(), "premium");

  EXPECT_EQ(admin.cambiarTipoDeMembresia(), true);
  EXPECT_EQ(admin.gettipoMembresia(), "estandar");
}
