#include "encriptacion.h"
#include <string.h>
#include "rle.h"
#include "lz78.h"
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

int prepararTextoComprimido(const char* desencriptado, int tamano, char* textoComprimido) {
    int numTernas = tamano / 3;
    int posicionActual = 0;

    for (int i = 0; i < numTernas; i++) {
        int pos = i * 3;
        int numero = abs(int(desencriptado[pos]) << 8 | int(desencriptado[pos + 1]));
        unsigned char caracter = desencriptado[pos + 2];

        char numberBuffer[10];
        int numberLength;
        numeroAString(numero, numberBuffer, numberLength);

        for (int j = 0; j < numberLength; j++) {
            textoComprimido[posicionActual++] = numberBuffer[j];
        }
        textoComprimido[posicionActual++] = caracter;
    }

    return posicionActual;
}

int probarRLE(char* desencriptado, int tamano, const char* pista,
              int n, int K, char*& texto_desencriptado) {

    int tamano_cadena_descomprimida = 0;
    int tamano_cadena_limpia = 0;

    // Limpiar cadena
    char* cadena_limpia = new char[tamano];
    limpiarCadena(cadena_limpia, desencriptado, tamano_cadena_descomprimida, tamano_cadena_limpia, tamano);

    // Descomprimir RLE
    char* cadena_descomprimida = new char[tamano_cadena_descomprimida];
    descomprimirRLE(cadena_limpia, tamano, cadena_descomprimida);

    // Verificar si contiene la pista
    bool encontrado = (cadena_descomprimida && strstr(cadena_descomprimida, pista) != nullptr);

    if (encontrado) {
        texto_desencriptado = cadena_descomprimida; // Transferir ownership
        delete[] cadena_limpia;
        return 0; // RLE
    } else {
        // Liberar memoria si no se encontró
        delete[] cadena_limpia;
        // delete[] cadena_descomprimida;
        return -1;
    }
}

int probarLZ78(char* desencriptado, int tamano, const char* pista,
               int n, int K, char*& texto_desencriptado) {

    // Preparar texto comprimido para LZ78
    int longitudTotal = calcularLongitudTotal(desencriptado, tamano);
    char* textoComprimido = new char[longitudTotal + 1];
    int posicionActual = prepararTextoComprimido(desencriptado, tamano, textoComprimido);
    textoComprimido[posicionActual] = '\0';

    int textLength = longitudString(textoComprimido);

    // Descomprimir LZ78
    char* salida_lz = descomprimirLZ78(textoComprimido, textLength);

    // Verificar si contiene la pista
    bool encontrado = (salida_lz && strstr(salida_lz, pista) != nullptr);

    // Liberar memoria intermedia
    delete[] textoComprimido;

    if (encontrado) {
        texto_desencriptado = salida_lz; // Transferir ownership
        return 1; // LZ78
    } else {
        delete[] salida_lz;
        return -1;
    }
}

int detectarMetodoYParametros(const char* encriptado, int& tamano, const char* pista,
                              int& n_out, int& K_out, char*& texto_desencriptado) {

    texto_desencriptado = nullptr; // Inicializar a nullptr

    // Probar todas las combinaciones de n y K
    for (int n = 1; n < 8; n++) {
        for (int K = 0; K < 256; K++) {

            // 1. Desencriptar
            char* desencriptado = desencriptar(encriptado, tamano, n, K);
            if (!desencriptado) continue;

            // 2. Probar RLE primero
            int resultado = probarRLE(desencriptado, tamano, pista, n, K, texto_desencriptado);
            if (resultado != -1) {
                delete[] desencriptado;
                n_out = n;
                K_out = K;
                return resultado; // 0 para RLE
            }

            // 3. Probar LZ78 solo si el tamaño es múltiplo de 3
            if (tamano % 3 == 0) {
                resultado = probarLZ78(desencriptado, tamano, pista, n, K, texto_desencriptado);
                if (resultado != -1) {
                    delete[] desencriptado;
                    n_out = n;
                    K_out = K;
                    return resultado; // 1 para LZ78
                }
            }

            // Liberar memoria antes de siguiente iteración
            delete[] desencriptado;
        }
    }

    return -1; // No se encontró combinación válida
}
