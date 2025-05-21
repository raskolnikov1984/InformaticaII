
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../huesped.h"
#include "../anfitrion.h"
#include "../alojamiento.h"
#include "../reserva.h"
#include "../usuario.h"
#include "../pago.h"

using namespace testing;
using namespace std;

class UdeAStay : public ::testing::Test {
public:
    Huesped* huesped;
    Anfitrion* anfitrion;
    Alojamiento* alojamiento;
    Reserva* reserva;
    Pago* pago;

    void SetUp() override {
        huesped = new Huesped("huesped", "1123455", 5, 3.5);
        anfitrion = new Anfitrion("anfitrion", "1123456", 10, 4.0);
        alojamiento = new Alojamiento(
            "Caetanos", "90666", "1123456", "Sao Paulo", "Sao luiz", "casa", "Km10", 530.5);
        reserva = new Reserva(
            3,
            1001,
            "APT203",
            "123456789",
            "TCredito",
            "lunes, 20 de mayo del 2025",
            "Solicito habitación silenciosa",
            450000.0
        );
        pago = new Pago("PSE", "2025-05-20", 250000.0);
    }

    void TearDown() override {
        delete huesped;
        delete anfitrion;
        delete alojamiento;
        delete reserva;
        delete pago;
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

TEST_F(UdeAStay, GettersFuncionanCorrectamente) {
    EXPECT_EQ(reserva->getDuracion(), 3);
    EXPECT_EQ(reserva->getCodigoReserva(), 1001);
    EXPECT_EQ(reserva->getCodigoAlojamiento(), "APT203");
    EXPECT_EQ(reserva->getDocumentoHuesped(), "123456789");
    EXPECT_EQ(reserva->getMetodoPago(), "TCredito");
    EXPECT_EQ(reserva->getFechaEntrada(), "lunes, 20 de mayo del 2025");
    EXPECT_EQ(reserva->getDescripcion(), "Solicito habitación silenciosa");
    EXPECT_DOUBLE_EQ(reserva->getMonto(), 450000.0);
}

TEST_F(UdeAStay, SettersModificanValores) {
    reserva->setDuracion(5);
    reserva->setMonto(600000.0);
    reserva->setDescripcion("Prefiero cama doble");

    EXPECT_EQ(reserva->getDuracion(), 5);
    EXPECT_DOUBLE_EQ(reserva->getMonto(), 600000.0);
    EXPECT_EQ(reserva->getDescripcion(), "Prefiero cama doble");
}


TEST_F(UdeAStay, DescripcionNoExcede1000Caracteres) {
    string larga(1200, 'x'); // Cadena de 1200 caracteres
    reserva->setDescripcion(larga);
    EXPECT_EQ(reserva->getDescripcion().length(), 1000);
}

TEST_F(UdeAStay, GettersPagoFuncionanCorrectamente) {
    EXPECT_EQ(pago->getMetodoPago(), "PSE");
    EXPECT_EQ(pago->getFechaPago(), "2025-05-20");
    EXPECT_DOUBLE_EQ(pago->getMonto(), 250000.0);
}

TEST_F(UdeAStay, SettersPagoModificanValores) {
    pago->setMetodoPago("TCredito");
    pago->setFechaPago("2025-06-01");
    pago->setMonto(310000.0);

    EXPECT_EQ(pago->getMetodoPago(), "TCredito");
    EXPECT_EQ(pago->getFechaPago(), "2025-06-01");
    EXPECT_DOUBLE_EQ(pago->getMonto(), 310000.0);
}
