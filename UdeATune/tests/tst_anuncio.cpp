#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "../anuncio.h"

class UdeATuneAnuncio : public ::testing::Test {
public:
  Anuncio anuncio;

  void SetUp() override {
    anuncio.setMensaje("¡Descubre los nuevos lanzamientos de la semana! No te pierdas lo mejor de la música.");
    anuncio.setCategoria('C');
    anuncio.setPrioridad(3);
  }
};

TEST_F(UdeATuneAnuncio, CreateAnuncio) {
  string expectedMensaje = "¡Descubre los nuevos lanzamientos de la semana! No te pierdas lo mejor de la música.";
  EXPECT_EQ(anuncio.getMensaje(), expectedMensaje);
  EXPECT_EQ(anuncio.getCategoria(), 'C');
  EXPECT_EQ(anuncio.getPrioridad(), 3);
}
