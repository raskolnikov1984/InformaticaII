#ifndef RESERVA_H
#define RESERVA_H

#include <string>
#include <iostream>

using namespace std;

class Reserva {
private:
    int duracion;                   // En noches
    int codigoReserva;             // Código único de la reserva
    string codigoAlojamiento;      // Código del alojamiento (no double, es una cadena)
    string documentoHuesped;       // Documento del huésped (también cadena por si contiene letras)
    string metodoPago;             // Método de pago: "PSE" o "TCredito"
    string fechaEntrada;           // Fecha de entrada (formato YYYY-MM-DD o nombreDía, día de mes de año)
    string descripcion;            // Hasta 1000 caracteres
    double monto;                  // Valor pagado

public:
    // Constructor
    Reserva(int duracion,
            int codigoReserva,
            const string& codigoAlojamiento,
            const string& documentoHuesped,
            const string& metodoPago,
            const string& fechaEntrada,
            const string& descripcion,
            double monto);
    string tabla = "reservas.txt";

    // Getters
    int getDuracion() const;
    int getCodigoReserva() const;
    string getCodigoAlojamiento() const;
    string getDocumentoHuesped() const;
    string getMetodoPago() const;
    string getFechaEntrada() const;
    string getDescripcion() const;
    double getMonto() const;

    // Setters
    void setDuracion(int duracion);
    void setCodigoReserva(int codigo);
    void setCodigoAlojamiento(const string& codigoAlojamiento);
    void setDocumentoHuesped(const string& documento);
    void setMetodoPago(const string& metodo);
    void setFechaEntrada(const string& fecha);
    void setDescripcion(const string& descripcion);
    void setMonto(double monto);

    // Métodos adicionales
    void mostrarComprobante() const;
};

#endif
