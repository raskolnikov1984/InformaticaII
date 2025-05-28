#include "alojamiento.h"
#include <stdexcept>

using namespace  std;


Alojamiento::Alojamiento()
    : nombre(""), codigoIdentificador(""), anfitrion(""), departamento(""), municipio(""),
    tipo(""), direccion(""), precioPorNoche(0){}

Alojamiento::Alojamiento(
    const string& nombre, const string& codigoIdentificador,
    const string& anfitrion, const string& departamento, const string& municipio,
    const string& tipo, const string& direccion, double precioPorNoche
    ) : nombre(nombre), codigoIdentificador(codigoIdentificador), anfitrion(anfitrion), departamento(departamento), municipio(municipio), tipo(tipo), direccion(direccion), precioPorNoche(precioPorNoche){

    if(tipo != "casa" && tipo != "apartamento"){
        throw invalid_argument("El Tipo de Alojamiento debe ser (casa, apartamento)");
    }
}
