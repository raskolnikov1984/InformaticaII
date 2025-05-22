#include <iostream>
#include <iostream>
#include <fstream>
#include "db.h"

using namespace std;


DB::DB()
    : indexUsuarios(0), indexReservas(0), indexHuespedes(0), indexAnfitriones(0), indexAlojamientos(0), indexAmenidades(0){
    // Inicializar nombres de archivos
    tablas.usuarios = "usuarios.txt";
    tablas.reservas = "reservas.txt";
    tablas.pagos = "pagos.txt";
    tablas.huespedes = "huespedes.txt";
    tablas.anfitriones = "anfitriones.txt";
    tablas.alojamientos = "alojamientos.txt";
    tablas.amenidades = "amenidades.txt";
}

void DB::inicializarBaseDeDatos() {
    // Crear un arreglo de punteros a los nombres de los archivos
    string* archivos[] = {
        &tablas.usuarios,
        &tablas.reservas,
        &tablas.pagos,
        &tablas.huespedes,
        &tablas.anfitriones,
        &tablas.alojamientos,
        &tablas.amenidades
    };

    for (int i = 0; i < 7; ++i) {
        ifstream archivo(*archivos[i]);
        if (!archivo) {
            ofstream nuevoArchivo(*archivos[i]);
            if (nuevoArchivo) {
                cout << "Archivo creado: " << *archivos[i] << endl;
            } else {
                cerr << "Error al crear el archivo: " << *archivos[i] << endl;
            }
        } else {
            cout << "Archivo ya existe: " << *archivos[i] << endl;
        }
    }
}

int DB::getIndexUsuarios() const
{
    return indexUsuarios;
}

void DB::setIndexUsuarios(int newIndexUsuarios)
{
    indexUsuarios = newIndexUsuarios;
}

int DB::getIndexReservas() const
{
    return indexReservas;
}

void DB::setIndexReservas(int newIndexReservas)
{
    indexReservas = newIndexReservas;
}

int DB::getIndexPagos() const
{
    return indexPagos;
}

void DB::setIndexPagos(int newIndexPagos)
{
    indexPagos = newIndexPagos;
}

int DB::getIndexHuespedes() const
{
    return indexHuespedes;
}

void DB::setIndexHuespedes(int newIndexHuespedes)
{
    indexHuespedes = newIndexHuespedes;
}

int DB::getIndexAnfitriones() const
{
    return indexAnfitriones;
}

void DB::setIndexAnfitriones(int newIndexAnfitriones)
{
    indexAnfitriones = newIndexAnfitriones;
}

int DB::getIndexAlojamientos() const
{
    return indexAlojamientos;
}

void DB::setIndexAlojamientos(int newIndexAlojamientos)
{
    indexAlojamientos = newIndexAlojamientos;
}

int DB::getIndexAmenidades() const
{
    return indexAmenidades;
}

void DB::setIndexAmenidades(int newIndexAmenidades)
{
    indexAmenidades = newIndexAmenidades;
}

tablasStructure DB::getTablas() const
{
    return tablas;
}

void DB::setTablas(const tablasStructure &newTablas)
{
    tablas = newTablas;
}
