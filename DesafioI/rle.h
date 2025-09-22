#ifndef RLE_H
#define RLE_H

struct cadenaComprimidaRLEstruct {
    char simbolo = '\0';
    int cantidad = 0;
};

cadenaComprimidaRLEstruct* comprimirRLE(char* cadena);

int* convertirToCadenaComprimida(cadenaComprimidaRLEstruct* segmentos);

char* descomprimirCadenaRLE(cadenaComprimidaRLEstruct* segmentos);

void imprimirCadenaComprimida(cadenaComprimidaRLEstruct* segmento);

unsigned char* encriptarRLE(cadenaComprimidaRLEstruct* segmentos, int n, int K);

void imprimirCadenaDesencriptada(unsigned char* cadenaDesencriptada);

#endif // RLE_H
