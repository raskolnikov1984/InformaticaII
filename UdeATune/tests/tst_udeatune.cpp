#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <string>
#include <stdexcept>
#include "../app.h"

using namespace std;

class UdeATune : public ::testing::Test {
protected:
  void SetUp() override {
    app = new App("/home/aserrador/Desktop/04-UdeA/InformaticaII/UdeATune");
    string usuario = "alejandro";
    string password = "alejandro123";

    app->iniciarSesion(usuario, password);
  }

  App* app;
};

TEST_F(UdeATune, VerificarAlmacenamientoExiste) {
  string ruta_almacenamiento = "/home/aserrador/Desktop/04-UdeA/InformaticaII/UdeATune";
  EXPECT_TRUE(app->setAlmacenamiento(ruta_almacenamiento));
}

TEST_F(UdeATune, VerificarAlmacenamientoNoExiste) {
  string ruta_almacenamiento_fake = "/UdeATune";
  EXPECT_THROW(app->setAlmacenamiento(ruta_almacenamiento_fake), runtime_error);
}

TEST_F(UdeATune, IngresarAlaAppPremium) {
  EXPECT_TRUE(app->enEjecusion);
  EXPECT_EQ(app->usuarioActual, "alejandro");
  EXPECT_EQ(app->tipoMembresia, "premium");
}
