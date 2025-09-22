#ifndef RLE_H
#define RLE_H

struct cadenaComprimidaRLEstruct {
    char simbolo = '\0';
    int cantidad = 0;
};

cadenaComprimidaRLEstruct* comprimirRLE(char* cadena);

int* convertirToCadenaComprimida(cadenaComprimidaRLEstruct* segmentos);

void imprimirCadenaComprimida(cadenaComprimidaRLEstruct* segmento);

#endif // RLE_H
