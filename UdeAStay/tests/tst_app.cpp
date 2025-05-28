#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../app/app.h"

using namespace testing;
using namespace std;


class AppTest : public ::testing::Test {
public:
    App* app;
    tablasStructure tablas;


    void SetUp() override {
        tablas.usuarios = "../tests/usuariosTest.csv";
        tablas.reservas = "../tests/reservasTest.csv";
        tablas.huespedes = "../tests/huespedesTest.csv";
        tablas.anfitriones = "../tests/anfitrionesTest.csv";
        tablas.alojamientos = "../tests/alojamientosTest.csv";
        tablas.amenidades = "../tests/amenidadesTest.csv";

        app = new App(tablas);
    }

    void TearDown()override {
        delete app;
    }
};

TEST_F(AppTest, CargarUsuarios){
    int numUsuarios = app->cargarUsuarios("../tests/usuariosTest.csv");
    EXPECT_GE(numUsuarios, 7);
}

TEST_F(AppTest, LoginValidoUsuario){
    LoginStruct expectedLogin;
    expectedLogin.tipoUsuario = "huesped";
    expectedLogin.numeroDocumento = "12345678";

    EXPECT_TRUE(app->validate_user("12345678", "passHuesped1"));
    EXPECT_EQ(app->contexStruct.login, expectedLogin);
}
TEST_F(AppTest, LoginInvalidoUsuario){
    EXPECT_FALSE(app->validate_user("test", "test"));
}
