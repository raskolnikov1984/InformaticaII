#ifndef PAGO_H
#define PAGO_H

#include <string>
#include <iostream>

using namespace std;

class Pago {
private:
    string metodoPago;   // "PSE", "TCredito"
    string fechaPago;    // Formato YYYY-MM-DD
    double monto;        // Valor pagado

public:
    Pago(const string& metodoPago, const string& fechaPago, double monto);
    string tabla = "pagos.txt";
    string getMetodoPago() const;
    string getFechaPago() const;
    double getMonto() const;

    void setMetodoPago(const string& metodoPago);
    void setFechaPago(const string& fechaPago);
    void setMonto(double monto);

    void mostrarPago() const;
};

#endif
