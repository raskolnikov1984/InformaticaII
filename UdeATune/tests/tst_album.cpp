#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "../album.h"

class UdeATuneAlbum : public ::testing::Test {
public:
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
  }
};

TEST_F(UdeATuneAlbum, Album) {
  EXPECT_EQ(azucarPaTi.getIdentificador(), "1");
  EXPECT_EQ(azucarPaTi.getArtista(), "Eddie Palmieri");
  EXPECT_EQ(azucarPaTi.getGenero(), "LatinJazz");
  EXPECT_EQ(azucarPaTi.getFechaLanzamiento(), "1965");
  EXPECT_EQ(azucarPaTi.getDuracion(), "34:06");
  EXPECT_EQ(azucarPaTi.getNombre(), "Azúcar pa' ti");
}
