#include <gtest/gtest.h>
#include <iostream>
#include "../app/app.h"

using namespace std;

int main(int argc, char *argv[])
{

    cout << "APP corriendo...\n";

    tablasStructure tablas;

    tablas.usuarios = "../tests/usuariosTest.csv";
    tablas.reservas = "../tests/reservasTest.csv";
    tablas.pagos = "../tests/pagosTest.csv";
    tablas.huespedes = "../tests/huespedesTest.csv";
    tablas.anfitriones = "../tests/anfitrionesTest.csv";
    tablas.alojamientos = "../tests/alojamientosTest.csv";
    tablas.amenidades = "../tests/amenidadesTest.csv";

    App* app = new App(tablas);
    app->run();
    delete app;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
