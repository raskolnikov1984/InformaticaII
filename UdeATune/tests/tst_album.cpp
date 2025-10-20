#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "../album.h"
#include "../cancion.h"

class UdeATuneAlbum : public ::testing::Test {
public:
  Album azucarPaTi;
  Cancion miSonsito;

  void SetUp() override {
    azucarPaTi.setIdentificador("1");
    azucarPaTi.setArtista("Eddie Palmieri");
    azucarPaTi.setGenero("LatinJazz");
    azucarPaTi.setFechaLanzamiento("1965");
    azucarPaTi.setDuracion("34:06");
    azucarPaTi.setNombre("Azúcar pa' ti");
    azucarPaTi.setSello("2020-03-02");
    azucarPaTi.setPuntuacion("Portada");

    miSonsito.setIdentificador("1");
    miSonsito.setNombre("Mi Sonsito");
    miSonsito.setDuracion("5:20");
    miSonsito.setUbicacion("ubicacion");
    miSonsito.setCreditos("Creditos");
    miSonsito.setReproducciones(10000);
  }
};

TEST_F(UdeATuneAlbum, Album) {
  EXPECT_EQ(azucarPaTi.getIdentificador(), "1");
  EXPECT_EQ(azucarPaTi.getArtista(), "Eddie Palmieri");
  EXPECT_EQ(azucarPaTi.getGenero(), "LatinJazz");
  EXPECT_EQ(azucarPaTi.getFechaLanzamiento(), "1965");
  EXPECT_EQ(azucarPaTi.getDuracion(), "34:06");
  EXPECT_EQ(azucarPaTi.getNombre(), "Azúcar pa' ti");
  EXPECT_EQ(azucarPaTi.canciones.getCapacidad(), 0);
}

TEST_F(UdeATuneAlbum, Cancion) {
  EXPECT_EQ(miSonsito.getIdentificador(), "1");
  EXPECT_EQ(miSonsito.getNombre(), "Mi Sonsito");
  EXPECT_EQ(miSonsito.getDuracion(), "5:20");
  EXPECT_EQ(miSonsito.getUbicacion(), "ubicacion");
  EXPECT_EQ(miSonsito.getCreditos(), "Creditos");
  EXPECT_EQ(miSonsito.getReproducciones(), 10000);
}

TEST_F(UdeATuneAlbum, AgregarCancion) {
  azucarPaTi.canciones.agregar(miSonsito);
  EXPECT_EQ(azucarPaTi.canciones.getCapacidad(), 1);
}
