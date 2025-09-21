#ifndef TOOLS_H
#define TOOLS_H

char * leerArchivo(const char* ruta_archivo);

long calcularTamanoArchivo(const char* ruta_archivo);

unsigned char* desencriptar(const char* cadena_encriptada, int tamano_cadena_encriptada, int n, int K);

unsigned char rotarAlaDerecha(unsigned char byte, int n);

#endif // TOOLS_H
