#ifndef DB_H
#define DB_H

#include <string>

using namespace std;

struct tablasStructure{
    string usuarios;
    string reservas;
    string pagos;
    string huespedes;
    string anfitriones;
    string alojamientos;
    string amenidades;
};


class DB
{
public:
    DB();
    void inicializarBaseDeDatos();
    int getIndexUsuarios() const;
    void setIndexUsuarios(int newIndexUsuarios);
    int getIndexReservas() const;
    void setIndexReservas(int newIndexReservas);
    int getIndexPagos() const;
    void setIndexPagos(int newIndexPagos);
    int getIndexHuespedes() const;
    void setIndexHuespedes(int newIndexHuespedex);
    int getIndexAnfitriones() const;
    void setIndexAnfitriones(int newIndexAnfitriones);
    int getIndexAlojamientos() const;
    void setIndexAlojamientos(int newIndexAlojamientos);
    int getIndexAmenidades() const;
    void setIndexAmenidades(int newIndexAmenidades);

    tablasStructure getTablas() const;
    void setTablas(const tablasStructure &newTablas);

private:
    int indexUsuarios;
    int indexReservas;
    int indexPagos;
    int indexHuespedes;
    int indexAnfitriones;
    int indexAlojamientos;
    int indexAmenidades;
    tablasStructure tablas;
};

#endif // DB_H
