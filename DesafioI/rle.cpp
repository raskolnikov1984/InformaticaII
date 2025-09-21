#include "rle.h"

cadenaComprimidaRLEstruct* comprimirRLE(char* cadena){
    char letra = '\0';
    int cantidadSegmentos = 0;

    cadenaComprimidaRLEstruct* segmentos = new cadenaComprimidaRLEstruct[100];
    cadenaComprimidaRLEstruct* segmento;

    for(int i=0; cadena[i] != '\0'; i++){
        if(cadena[i] != letra){
            segmento = &segmentos[cantidadSegmentos];
            letra = cadena[i];
            segmento->simbolo = cadena[i];
            segmento->cantidad = 1;
            cantidadSegmentos++;
        } else{
            segmento->cantidad += 1;
        }
    }
    return segmentos;
}
