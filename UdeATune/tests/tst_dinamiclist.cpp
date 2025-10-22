#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "../estructuras_datos/lista_dinamica.h"

using namespace std;
// Clase de prueba para Usuario
class Usuario {
public:
    string nombre;
    int id;

    Usuario() : nombre(""), id(0) {}
    Usuario(const string& n, int i) : nombre(n), id(i) {}

    bool operator==(const Usuario& other) const {
        return nombre == other.nombre && id == other.id;
    }
};

TEST(ListaDinamicaTest, ConstructorPorDefecto) {
    ListaDinamica<int> lista;
    EXPECT_EQ(lista.getCapacidad(), 0);
    EXPECT_EQ(lista.obtenerTamaño(), 0);
    EXPECT_TRUE(lista.estaVacia());
}

TEST(ListaDinamicaTest, ConstructorConCapacidad) {
    ListaDinamica<int> lista(10);
    EXPECT_EQ(lista.getCapacidad(), 10);
    EXPECT_EQ(lista.obtenerTamaño(), 0);
    EXPECT_TRUE(lista.estaVacia());
}

TEST(ListaDinamicaTest, ConstructorConCapacidadCero) {
    ListaDinamica<int> lista(0);
    EXPECT_EQ(lista.getCapacidad(), 0);
    EXPECT_EQ(lista.obtenerTamaño(), 0);
    EXPECT_TRUE(lista.estaVacia());
}

TEST(ListaDinamicaTest, AgregarElementos) {
    ListaDinamica<int> numeros;

    numeros.agregar(10);
    numeros.agregar(20);
    numeros.agregar(30);

    EXPECT_EQ(numeros.obtenerTamaño(), 3);
    EXPECT_EQ(numeros[0], 10);
    EXPECT_EQ(numeros[1], 20);
    EXPECT_EQ(numeros[2], 30);
}

TEST(ListaDinamicaTest, InsertarElementos) {
    ListaDinamica<std::string> palabras;

    palabras.agregar("mundo");
    palabras.insertar(0, "hola");
    palabras.insertar(2, "c++");

    EXPECT_EQ(palabras.obtenerTamaño(), 3);
    EXPECT_EQ(palabras[0], "hola");
    EXPECT_EQ(palabras[1], "mundo");
    EXPECT_EQ(palabras[2], "c++");
}

TEST(ListaDinamicaTest, EliminarElementos) {
    ListaDinamica<int> lista;

    lista.agregar(1);
    lista.agregar(2);
    lista.agregar(3);
    lista.agregar(4);

    lista.eliminar(1); // Eliminar el elemento en posición 1 (valor 2)

    EXPECT_EQ(lista.obtenerTamaño(), 3);
    EXPECT_EQ(lista[0], 1);
    EXPECT_EQ(lista[1], 3);
    EXPECT_EQ(lista[2], 4);

    lista.eliminarUltimo();
    EXPECT_EQ(lista.obtenerTamaño(), 2);
}


TEST(ListaDinamicaTest, AccesoElementosBasico) {
    ListaDinamica<int> lista;

    lista.agregar(10);
    lista.agregar(20);

    EXPECT_EQ(lista.primero(), 10);
    EXPECT_EQ(lista.ultimo(), 20);
    EXPECT_EQ(lista.obtener(1), 20);
}

TEST(ListaDinamicaTest, AccesoSeguro) {
    ListaDinamica<int> lista;

    lista.agregar(42);
    EXPECT_NO_THROW(lista.obtener(0));
    EXPECT_THROW(lista.obtener(1), std::out_of_range);
}


TEST(ListaDinamicaTest, ListaVacia) {
    ListaDinamica<int> lista;

    EXPECT_TRUE(lista.estaVacia());
    EXPECT_EQ(lista.obtenerTamaño(), 0);

    lista.agregar(1);
    EXPECT_FALSE(lista.estaVacia());

    lista.limpiar();
    EXPECT_TRUE(lista.estaVacia());
}

TEST(ListaDinamicaTest, LimpiarLista) {
    ListaDinamica<std::string> lista;

    lista.agregar("a");
    lista.agregar("b");
    lista.agregar("c");

    EXPECT_EQ(lista.obtenerTamaño(), 3);

    lista.limpiar();
    EXPECT_EQ(lista.obtenerTamaño(), 0);
    EXPECT_TRUE(lista.estaVacia());
}

TEST(ListaDinamicaTest, Redimensionar) {
    ListaDinamica<int> lista;

    lista.agregar(1);
    lista.agregar(2);

    lista.redimensionar(5, 0);

    EXPECT_GE(lista.getCapacidad(), 5);
    EXPECT_EQ(lista.obtenerTamaño(), 5);
    EXPECT_EQ(lista[0], 1);
    EXPECT_EQ(lista[1], 2);
    EXPECT_EQ(lista[2], 0);
}

TEST(ListaDinamicaTest, ReservarCapacidad) {
    ListaDinamica<int> lista;

    lista.reservar(50);
    EXPECT_GE(lista.getCapacidad(), 50);
    EXPECT_EQ(lista.obtenerTamaño(), 0);
}

TEST(ListaDinamicaTest, CopiarLista) {
    ListaDinamica<int> original;
    original.agregar(1);
    original.agregar(2);
    original.agregar(3);

    ListaDinamica<int> copia(original);

    EXPECT_EQ(copia.obtenerTamaño(), original.obtenerTamaño());
    EXPECT_EQ(copia[0], original[0]);
    EXPECT_EQ(copia[1], original[1]);
    EXPECT_EQ(copia[2], original[2]);
}

TEST(ListaDinamicaTest, AsignacionLista) {
    ListaDinamica<int> lista1;
    lista1.agregar(1);
    lista1.agregar(2);

    ListaDinamica<int> lista2;
    lista2 = lista1;

    EXPECT_EQ(lista2.obtenerTamaño(), 2);
    EXPECT_EQ(lista2[0], 1);
    EXPECT_EQ(lista2[1], 2);
}

TEST(ListaDinamicaTest, IntercambiarListas) {
    ListaDinamica<int> lista1;
    lista1.agregar(1);
    lista1.agregar(2);

    ListaDinamica<int> lista2;
    lista2.agregar(3);
    lista2.agregar(4);
    lista2.agregar(5);

    lista1.intercambiar(lista2);

    EXPECT_EQ(lista1.obtenerTamaño(), 3);
    EXPECT_EQ(lista2.obtenerTamaño(), 2);
    EXPECT_EQ(lista1[0], 3);
    EXPECT_EQ(lista2[0], 1);
}

TEST(ListaDinamicaTest, ListaVaciaComportamiento) {
    ListaDinamica<int> lista;

    EXPECT_THROW(lista.primero(), out_of_range);
    EXPECT_THROW(lista.ultimo(), out_of_range);
    EXPECT_THROW(lista.obtener(0), out_of_range);

    EXPECT_NO_THROW(lista.eliminarUltimo());
    EXPECT_NO_THROW(lista.limpiar());
}

TEST(ListaDinamicaTest, MultipleOperaciones) {
    ListaDinamica<int> lista;

    for (int i = 0; i < 100; ++i) {
        lista.agregar(i);
    }

    EXPECT_EQ(lista.obtenerTamaño(), 100);
    EXPECT_GE(lista.getCapacidad(), 100);

    EXPECT_EQ(lista[0], 0);
    EXPECT_EQ(lista[99], 99);
}
