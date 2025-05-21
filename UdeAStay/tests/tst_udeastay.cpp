
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../huesped.h"
#include "../anfitrion.h"
#include "../alojamiento.h"
#include "../usuario.h"

using namespace testing;
using namespace std;

class UdeAStay : public ::testing::Test {
public:
    Huesped* huesped;
    Anfitrion* anfitrion;
    Alojamiento* alojamiento;

    void SetUp() override {
        huesped = new Huesped("huesped", "1123455", 5, 3.5);
        anfitrion = new Anfitrion("anfitrion", "1123456", 10, 4.0);
        alojamiento = new Alojamiento(
            "Caetanos", "90666", "1123456", "Sao Paulo", "Sao luiz", "casa", "Km10", 530.5);
    }

    void TearDown() override {
        delete huesped;
        delete anfitrion;
        delete alojamiento;
    }
};


TEST_F(UdeAStay, CrearUsuarioTipoHuesped)
{
    EXPECT_EQ(huesped->getNumeroDocumento(), "1123455");
    EXPECT_EQ(huesped->getAntiguedad(), 5);
    EXPECT_EQ(huesped->getPuntuacion(), 3.5);
    EXPECT_EQ(huesped->getTipoUsuario(), "huesped");
}

TEST_F(UdeAStay, CrearUsuarioTipoAnfitrion)
{
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

TEST_F(UdeAStay, CrearAlojamiento){
    EXPECT_EQ(alojamiento->getNombre(), "Caetanos");
    EXPECT_EQ(alojamiento->getCodigoIdentificador(), "90666");
    EXPECT_EQ(alojamiento->getAnfitrion(), "1123456");
    EXPECT_EQ(alojamiento->getDepartamento(), "Sao Paulo");
    EXPECT_EQ(alojamiento->getMunicipio(), "Sao luiz");
    EXPECT_EQ(alojamiento->getTipo(), "casa");
    EXPECT_EQ(alojamiento->getDireccion(), "Km10");
    EXPECT_EQ(alojamiento->getPrecioPorNoche(), 530.5);
}

TEST_F(UdeAStay, CrearAlojamientoTipoInvalido){
    EXPECT_THROW(new Alojamiento(
                     "Caetanos", "90666", "1123456", "Sao Paulo", "Sao luiz", "contenedor", "Km10", 530.5);, std::invalid_argument);
}
