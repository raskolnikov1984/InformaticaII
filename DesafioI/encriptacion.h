#ifndef ENCRIPTACION_H
#define ENCRIPTACION_H

unsigned char* desencriptar(const char* cadena_encriptada, int tamano, int n, int K);

unsigned char rotarAlaDerecha(unsigned char byte, int n);

unsigned char rotarAlaIzquierda(unsigned char byte, int n);

int detectarMetodoYParametros(const char* encriptado, int& tamano, const char* pista,
                              int& n_out, int& K_out, char*& texto_desencriptado);
#endif // ENCRIPTACION_H
