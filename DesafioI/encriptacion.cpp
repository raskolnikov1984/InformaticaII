#include "encriptacion.h"
#include <string.h>
#include "rle.h"
#include "files.h"
#include <iostream>

using namespace std;

char* desencriptar(const char* cadena_encriptada, int tamano, int n, int K) {
    char* cadena_desencriptada = new  char[tamano + 1];

    for(int i = 0; i < tamano; i++) {
        unsigned char byte = cadena_encriptada[i];
        unsigned char b1 = byte ^ K;           // XOR inverso
        unsigned char b2 = rotarAlaDerecha(b1, n); // Rotación inversa
        cadena_desencriptada[i] = b2;
    }

    cadena_desencriptada[tamano] = '\0';

    return cadena_desencriptada;
}

unsigned char rotarAlaDerecha(unsigned char byte, int n) {
    return (byte >> n) | (byte << (8 - n));
}


unsigned char rotarAlaIzquierda(unsigned char byte, int n){
    return (byte << n | byte >> (8 - n));
}

int detectarMetodoYParametros(const char* encriptado, int& tamano, const char* pista,
                              int& n_out, int& K_out, char*& texto_desencriptado) {

    // Probar todas las combinaciones de n y K
    for (int n = 1; n < 8; n++) {
        for (int K = 0; K < 256; K++) {
            int tamano_cadena_descomprimida = 0;
            int tamano_cadena_limpia = 0;

            // Desencriptar
            char* desencriptado = desencriptar(
                encriptado, tamano, n, K);

            if (!desencriptado) continue;

            char* cadena_limpia = new char[tamano];
            char* cadena_descomprimida;

            limpiarCadena(cadena_limpia, desencriptado, tamano_cadena_descomprimida, tamano_cadena_limpia, tamano);
            cadena_descomprimida = new char[tamano_cadena_descomprimida];
            descomprimirRLE(cadena_limpia, tamano, cadena_descomprimida);

            // Intentar RLE primero (más simple)

            if (cadena_descomprimida && strstr(cadena_descomprimida, pista) != nullptr) {
                texto_desencriptado = new char[tamano_cadena_descomprimida];
                n_out = n;
                K_out = K;
                texto_desencriptado = cadena_descomprimida;

                return 0; // RLE
            }

            // Intentar LZ78 (solo si el tamaño es múltiplo de 3)
            // if (tamano % 3 == 0) {
            //     char* texto_lz = descomprimirLZ78(desencriptado, tamano);
            //     if (texto_lz && strstr(texto_lz, pista) != nullptr) {
            //         n_out = n;
            //         K_out = K;
            //         texto_desencriptado = texto_lz;
            //         delete[] desencriptado;
            //         return 1; // LZ78
            //     }
            //     delete[] texto_lz;
            // }

            delete[] desencriptado;
        }
    }

    return -1; // No se encontró combinación válida
}
