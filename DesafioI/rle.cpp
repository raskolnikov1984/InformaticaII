#include <iostream>
#include <cctype>

using namespace std;

bool esFormatoRLEValido(const char* cadena, int tamano_cadena_limpia){
    for(int i=0; i < tamano_cadena_limpia; i++){
        if(!isalpha(cadena[i]) && !isdigit(static_cast<int>(cadena[i])) && cadena[i] != '\0'){;
            return false;
        }
    }

    return true;
}

void descomprimirRLE(char*& cadena_limpia, int tamano_cadena_limpia, char*& cadena_descomprimida) {

    if (!esFormatoRLEValido(cadena_limpia, tamano_cadena_limpia)) {
        cerr << "Error: Formato RLE inválido" << endl;
        if (cadena_descomprimida) {
            cadena_descomprimida[0] = '\0';
        }

        return;
    }

    // Validaciones iniciales críticas
    if (!cadena_limpia) {
        cerr << "Error: cadena_limpia es nula" << endl;
        return;
    }

    if (!cadena_descomprimida) {
        cerr << "Error: cadena_descomprimida es nula" << endl;
        return;
    }

    if (cadena_limpia[0] == '\0') {
        cadena_descomprimida[0] = '\0';
        return;
    }

    int j = 0;
    int pos = 0;

    while (cadena_limpia[j] != '\0') {
        // Validar que empiece con dígito
        if (!isdigit(cadena_limpia[j])) {
            cerr << "Error: Formato inválido en posición " << j << endl;
            cadena_descomprimida[0] = '\0';
            return;
        }

        int cantidad = 0;

        // Leer número
        while (isdigit(cadena_limpia[j])) {
            cantidad = cantidad * 10 + (cadena_limpia[j] - '0');
            j++;

            if (cantidad > 1000000) {
                cerr << "Error: Número demasiado grande" << endl;
                cadena_descomprimida[0] = '\0';
                return;
            }
        }

        if (cadena_limpia[j] == '\0') {
            cerr << "Error: Formato incompleto" << endl;
            cadena_descomprimida[0] = '\0';
            return;
        }

        char caracter = cadena_limpia[j];
        j++;

        for (int k = 0; k < cantidad; k++) {
            cadena_descomprimida[pos] = caracter;
            pos++;
        }
    }

    cadena_descomprimida[pos] = '\0';
}
