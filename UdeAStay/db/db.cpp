#include <iostream>
#include <fstream>
#include "db.h"

using namespace std;


DB::DB()
    : indexUsuarios(0), indexReservas(0), indexHuespedes(0), indexAnfitriones(0), indexAlojamientos(0), indexAmenidades(0){
    // Inicializar nombres de archivos
    tablas.usuarios = "usuarios.csv";
    tablas.reservas = "reservas.csv";
    tablas.pagos = "pagos.csv";
    tablas.huespedes = "huespedes.csv";
    tablas.anfitriones = "anfitriones.csv";
    tablas.alojamientos = "alojamientos.csv";
    tablas.amenidades = "amenidades.csv";
}

void DB::inicializarBaseDeDatos() {
    struct {
        string& archivo;
        string columnas;
    } archivos[] = {
        {tablas.usuarios, "tipoUsuario,usuario,password"},
        {tablas.reservas, "duracion,codigoReserva,codigoAlojamiento,documentoHuesped,fechaEntrada,descripcion"},
        {tablas.pagos, "metodoPago,fechaPago,monto"},
        {tablas.huespedes, "tipoUsuario,numeroDocumento,antiguedad,puntuacion"},
        {tablas.anfitriones, "tipoUsuario,numeroDocumento,antiguedad,puntuacion"},
        {tablas.alojamientos, "nombre,codigoIdentificador,anfitrion,departamento,municipio,tipo,direccion,precioPorNoche"},
        {tablas.amenidades, "nombre,alojamiento"}
    };

    for (const auto& archivo : archivos) {
        ifstream file(archivo.archivo);
        if (!file) {
            ofstream nuevoArchivo(archivo.archivo);
            if (nuevoArchivo) {
                nuevoArchivo << archivo.columnas << endl;
                cout << "Archivo creado: " << archivo.archivo << " con columnas: " << archivo.columnas << endl;
            } else {
                cerr << "Error al crear el archivo: " << archivo.archivo << endl;
            }
        } else {
            cout << "Archivo ya existe: " << archivo.archivo << endl;
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
