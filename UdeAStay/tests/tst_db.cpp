#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <fstream>
#include "../db/db.h"

using namespace testing;
using namespace std;


class DataBase : public ::testing::Test {
public:
    DB* db_app;
    tablasStructure tablas;

    void SetUp() override {
        tablas.usuarios = "usuarios.txt";
        tablas.reservas = "reservas.txt";
        tablas.huespedes = "huespedes.txt";
        tablas.anfitriones = "anfitriones.txt";
        tablas.alojamientos = "alojamientos.txt";
        tablas.amenidades = "amenidades.txt";

        db_app = new DB(tablas);
    }

    void TearDown() override {
        const string archivos[] = {
            tablas.usuarios,
            tablas.reservas,
            tablas.huespedes,
            tablas.anfitriones,
            tablas.alojamientos,
            tablas.amenidades,
        };

        for (const auto& archivo : archivos) {
            remove(archivo.c_str());
        }

        delete db_app;
    }
};

TEST_F(DataBase, EstadoInicialIndixBaseDatos){
    EXPECT_EQ(db_app->getIndexUsuarios(), 0);
    EXPECT_EQ(db_app->getIndexReservas(), 0);
    EXPECT_EQ(db_app->getIndexHuespedes(), 0);
    EXPECT_EQ(db_app->getIndexAnfitriones(), 0);
    EXPECT_EQ(db_app->getIndexAlojamientos(), 0);
    EXPECT_EQ(db_app->getIndexAmenidades(), 0);
}

TEST_F(DataBase, AsignarNombresATablas){
    tablasStructure tablas;
    tablas.usuarios = "usuarios.txt";
    tablas.reservas = "reservas.txt";
    tablas.huespedes = "huespedes.txt";
    tablas.anfitriones = "anfitriones.txt";
    tablas.alojamientos = "alojamientos.txt";
    tablas.amenidades = "amenidades.txt";

    db_app->setTablas(tablas);


    EXPECT_EQ(db_app->getTablas().usuarios, "usuarios.txt");
    EXPECT_EQ(db_app->getTablas().reservas, "reservas.txt");
    EXPECT_EQ(db_app->getTablas().huespedes, "huespedes.txt");
    EXPECT_EQ(db_app->getTablas().anfitriones, "anfitriones.txt");
    EXPECT_EQ(db_app->getTablas().alojamientos, "alojamientos.txt");
    EXPECT_EQ(db_app->getTablas().amenidades, "amenidades.txt");
}

TEST_F(DataBase, InicializarBaseDeDatos_CreaArchivos) {
    // Llamar al método para inicializar la base de datos
    db_app->inicializarBaseDeDatos();

    // Verificar que los archivos se hayan creado correctamente
    const string archivos[] = {
        tablas.usuarios,
        tablas.reservas,
        tablas.huespedes,
        tablas.anfitriones,
        tablas.alojamientos,
        tablas.amenidades,
    };

    for (const auto& archivo : archivos) {
        std::ifstream file(archivo);
        EXPECT_TRUE(file.is_open()) << "El archivo " << archivo << " no fue creado.";
        file.close(); // Cerrar el archivo después de verificar
    }
}
