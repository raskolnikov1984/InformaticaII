#include <iostream>
#include "rle.h"

using namespace std;

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

int* convertirToCadenaComprimida(cadenaComprimidaRLEstruct* segmentos){
    int* cadenaComprimida = new int[100];
    int posicion = 0;
    int caracteres = 0;

    while(segmentos[posicion].cantidad != 0 ){
        cadenaComprimida[caracteres] = segmentos[posicion].cantidad;
        caracteres++;
        cadenaComprimida[caracteres] = segmentos[posicion].simbolo;
        caracteres++;
        posicion++;
    }

    return cadenaComprimida;
}

void imprimirCadenaComprimida(cadenaComprimidaRLEstruct* segmento){
    int posicion = 0;

    int* cadenaComprimida = convertirToCadenaComprimida(segmento);

    while(*(cadenaComprimida+posicion) != '\0'){
        int caracter = *(cadenaComprimida+posicion);

        if(caracter >= static_cast<int>('A') && caracter <= static_cast<int>('Z') || caracter >= static_cast<int>('a') && caracter <= static_cast<int>('z')){
            cout << static_cast<char>(caracter);
        } else {
            cout << caracter;
        }
        posicion++;
    }

    delete[] cadenaComprimida;
}

char* descomprimirCadenaRLE(cadenaComprimidaRLEstruct* segmentos){
    char* cadenaDescomprimida = new char[100];

    int posicion = 0;
    int caracteres = 0;

    while(segmentos[posicion].simbolo != '\0'){
        for(int i=0; i < segmentos[posicion].cantidad; i++){
            cadenaDescomprimida[caracteres] = segmentos[posicion].simbolo;
            caracteres++;
        }
        posicion++;
    }

    return cadenaDescomprimida;
}
