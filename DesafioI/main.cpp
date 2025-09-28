#include <iostream>
#include "files.h"
#include "encriptacion.h"
#include "lz78.h"


using namespace std;


int main(){
    const char archivo_encriptado[] = "/home/rodia/Desktop/04-UdeA/InformaticaII/DesafioI/dataset/Encriptado4.txt";
    const char archivo_pista[] = "/home/rodia/Desktop/04-UdeA/InformaticaII/DesafioI/dataset/pista4.txt";
    const char* encriptado = leerArchivo(archivo_encriptado);
    const char* pista = leerArchivo(archivo_pista);
    char* texto_desencriptado;

    int tamano = calcularTamanoArchivo(archivo_encriptado);
    char* desencriptado = desencriptar(encriptado, tamano, 3, 0x5A);

    int numTernas = tamano / 3;
    int longitudTotal = calcularLongitudTotal(desencriptado, tamano);

    char* textoComprimido = new char[longitudTotal + 1]; // +1 para '\0'

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

    textoComprimido[posicionActual] = '\0';


    int textLength = longitudString(textoComprimido);

    descomprimirLZ78(textoComprimido, textLength);

    imprimirResultado();

    limpiar();

    delete[] textoComprimido;

    return 0;
}
