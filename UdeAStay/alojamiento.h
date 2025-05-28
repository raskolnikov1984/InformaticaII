#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H

#include <string>

using namespace std;

class Alojamiento
{
private:
    string nombre;
    string codigoIdentificador;
    string anfitrion;
    string departamento;
    string municipio;
    string tipo;
    string direccion;
    double precioPorNoche;


public:
    Alojamiento();
    Alojamiento(
        const string& nombre,
        const string& codigoIdentificador,
        const string& anfitrion,
        const string& departamento,
        const string& municipio,
        const string& tipo,
        const string& direccion,
        double precioPorNoche);
        string tabla = "alojamientos.txt";

    // Getters
    string getNombre() const { return this->nombre; }
    string getCodigoIdentificador() const { return this->codigoIdentificador; }
    string getAnfitrion() const { return this->anfitrion; }
    string getDepartamento() const { return this->departamento; }
    string getMunicipio() const { return this->municipio; }
    string getTipo() const { return this->tipo; }
    string getDireccion() const { return this->direccion; }
    double getPrecioPorNoche() const { return this->precioPorNoche; }

    // Setters
    void setNombre(const string& nuevoNombre) { this->nombre = nuevoNombre; }
    void setCodigoIdentificador(const string& nuevoCodigo) { this->codigoIdentificador = nuevoCodigo; }
    void setAnfitrion(const string& nuevoAnfitrion) { this->anfitrion = nuevoAnfitrion; }
    void setDepartamento(const string& nuevoDepartamento) { this->departamento = nuevoDepartamento; }
    void setMunicipio(const string& nuevoMunicipio) { this->municipio = nuevoMunicipio; }
    void setTipo(const string& nuevoTipo) { this->tipo = nuevoTipo; }
    void setDireccion(const string& nuevaDireccion) { this->direccion = nuevaDireccion; }
    void setPrecioPorNoche(double nuevoPrecio) { this->precioPorNoche = nuevoPrecio; }
};

#endif // ALOJAMIENTO_H
