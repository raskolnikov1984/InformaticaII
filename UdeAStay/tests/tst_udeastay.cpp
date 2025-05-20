
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../huesped.h"
#include "../anfitrion.h"
#include "../usuario.h"

using namespace testing;
using namespace std;

class UdeAStay : public ::testing::Test {
public:
    Huesped* huesped;
    Anfitrion* anfitrion;
};


TEST_F(UdeAStay, CrearUsuarioTipoHuesped)
{
    huesped = new Huesped("huesped", "1123455", 5, 3.5);
    EXPECT_EQ(huesped->getNumeroDocumento(), "1123455");
    EXPECT_EQ(huesped->getAntiguedad(), 5);
    EXPECT_EQ(huesped->getPuntuacion(), 3.5);
    EXPECT_EQ(huesped->getTipoUsuario(), "huesped");
}

TEST_F(UdeAStay, CrearUsuarioTipoAnfitrion)
{
    anfitrion = new Anfitrion("anfitrion", "1123456", 10, 4.0);
    EXPECT_EQ(anfitrion->getNumeroDocumento(), "1123456");
    EXPECT_EQ(anfitrion->getAntiguedad(), 10);
    EXPECT_EQ(anfitrion->getPuntuacion(), 4.0);
    EXPECT_EQ(anfitrion->getTipoUsuario(), "anfitrion");
}

TEST_F(UdeAStay, CrearUsuarioTipoInvalido)
{
    EXPECT_THROW(new Usuario("invalido", "123456789", 12, 5.0), std::invalid_argument);
}

TEST_F(UdeAStay, CrearUsuarioPuntuacionInvalida)
{
    EXPECT_THROW(new Usuario("huesped", "123456783", 12, 20.1), std::invalid_argument);
}
