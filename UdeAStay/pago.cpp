#include "pago.h"

Pago::Pago(const string& metodoPago, const string& fechaPago, double monto)
    : metodoPago(metodoPago), fechaPago(fechaPago), monto(monto) {}

// Getters
string Pago::getMetodoPago() const { return metodoPago; }
string Pago::getFechaPago() const { return fechaPago; }
double Pago::getMonto() const { return monto; }

// Setters
void Pago::setMetodoPago(const string& metodoPago) { this->metodoPago = metodoPago; }
void Pago::setFechaPago(const string& fechaPago) { this->fechaPago = fechaPago; }
void Pago::setMonto(double monto) { this->monto = monto; }

// Mostrar
void Pago::mostrarPago() const {
    cout << "Método de Pago: " << metodoPago << endl;
    cout << "Fecha de Pago: " << fechaPago << endl;
    cout << "Monto: $" << monto << endl;
}
