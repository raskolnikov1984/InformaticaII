#ifndef FILES_H
#define FILES_H

char * leerArchivo(const char* ruta_archivo);

long calcularTamanoArchivo(const char* ruta_archivo);

void limpiarCadena(char*& cadena_limpia, char* archivo_desencriptado, int& tamano_cadena_descomprimida, int& tamano_cadena_limpia,int tamano);

#endif // FILES_H
