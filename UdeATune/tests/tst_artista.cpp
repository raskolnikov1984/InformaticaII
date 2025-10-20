#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "../artista.h"
#include "../album.h"

class UdeATuneArtista : public ::testing::Test {

public:
  Artista eddiePalmieri;
  Album azucarPaTi;

  void SetUp() override {
    azucarPaTi.setIdentificador("1");
    azucarPaTi.setArtista("Eddie Palmieri");
    azucarPaTi.setGenero("LatinJazz");
    azucarPaTi.setFechaLanzamiento("1965");
    azucarPaTi.setDuracion("34:06");
    azucarPaTi.setNombre("Azúcar pa' ti");
    azucarPaTi.setSello("2020-03-02");
    azucarPaTi.setPuntuacion("Portada");

    eddiePalmieri.setIdentificador("1");
    eddiePalmieri.setEdad(88);
    eddiePalmieri.setPais("Puerto Rico");
    eddiePalmieri.setSeguidores(115544);
    eddiePalmieri.setPosicionTendencias(25);
  }
};

TEST_F(UdeATuneArtista, CrearArtista) {
    EXPECT_EQ(eddiePalmieri.getIdentificador(), "1");
    EXPECT_EQ(eddiePalmieri.getEdad(), 88);
    EXPECT_EQ(eddiePalmieri.getPais(), "Puerto Rico");
    EXPECT_EQ(eddiePalmieri.getSeguidores(),115544);
    EXPECT_EQ(eddiePalmieri.getPosicionTendencias(), 25);
}
