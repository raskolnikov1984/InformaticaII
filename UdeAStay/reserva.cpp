#include "reserva.h"

// Constructor
Reserva::Reserva(int duracion, int codigoReserva, const string& codigoAlojamiento,
                 const string& documentoHuesped, const string& metodoPago,
                 const string& fechaEntrada, const string& descripcion, double monto)
    : duracion(duracion), codigoReserva(codigoReserva), codigoAlojamiento(codigoAlojamiento),
    documentoHuesped(documentoHuesped), metodoPago(metodoPago),
    fechaEntrada(fechaEntrada), descripcion(descripcion), monto(monto) {}

// Getters
int Reserva::getDuracion() const { return duracion; }
int Reserva::getCodigoReserva() const { return codigoReserva; }
string Reserva::getCodigoAlojamiento() const { return codigoAlojamiento; }
string Reserva::getDocumentoHuesped() const { return documentoHuesped; }
string Reserva::getMetodoPago() const { return metodoPago; }
string Reserva::getFechaEntrada() const { return fechaEntrada; }
string Reserva::getDescripcion() const { return descripcion; }
double Reserva::getMonto() const { return monto; }

// Setters
void Reserva::setDuracion(int duracion) { this->duracion = duracion; }
void Reserva::setCodigoReserva(int codigo) { this->codigoReserva = codigo; }
void Reserva::setCodigoAlojamiento(const string& codigoAlojamiento) { this->codigoAlojamiento = codigoAlojamiento; }
void Reserva::setDocumentoHuesped(const string& documento) { this->documentoHuesped = documento; }
void Reserva::setMetodoPago(const string& metodo) { this->metodoPago = metodo; }
void Reserva::setFechaEntrada(const string& fecha) { this->fechaEntrada = fecha; }
void Reserva::setDescripcion(const string& descripcion) {
    if (descripcion.length() <= 1000)
        this->descripcion = descripcion;
    else
        this->descripcion = descripcion.substr(0, 1000); // Trunca si es muy largo
}
void Reserva::setMonto(double monto) { this->monto = monto; }

// Método adicional
void Reserva::mostrarComprobante() const {
    cout << "-----------------------------" << endl;
    cout << "Confirmación de Reserva #" << codigoReserva << endl;
    cout << "Huésped: " << documentoHuesped << endl;
    cout << "Alojamiento: " << codigoAlojamiento << endl;
    cout << "Fecha de Entrada: " << fechaEntrada << endl;
    cout << "Duración: " << duracion << " noche(s)" << endl;
    cout << "Método de Pago: " << metodoPago << endl;
    cout << "Monto: $" << monto << endl;
    cout << "-----------------------------" << endl;
}
