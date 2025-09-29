#include <iostream>
#include "files.h"
#include "encriptacion.h"
#include "lz78.h"
#include <iomanip> // Para std::setw y std::setfill

using namespace std;


int main(){
    const char archivo_encriptado[] = "/home/rodia/Documents/DesafioI/dataset/Encriptado2.txt";
    const char archivo_pista[] = "/home/rodia/Documents/DesafioI/dataset/pista2.txt";
    const char* encriptado = leerArchivo(archivo_encriptado);
    const char* pista = leerArchivo(archivo_pista);
    char* texto_desencriptado;

    int tamano = calcularTamanoArchivo(archivo_encriptado);

    int metodo, n_out, K_out;

    metodo = detectarMetodoYParametros(
        encriptado, tamano, pista, n_out, K_out, texto_desencriptado);

    cout << "=======================================" << endl;
    cout << "          TEXTO DESENCRIPTADO          " << endl;
    cout << "=======================================" << endl;
    cout << endl;
    cout << texto_desencriptado << endl;
    cout << endl;
    cout << "=======================================" << endl;
    cout << endl;
    cout << left << setw(15) << "Metodo:" << metodo << endl;
    cout << left << setw(15) << "n OUT:" << n_out << endl;
    cout << left << setw(15) << "K out:" << K_out << endl;
    cout << endl;
    cout << "=======================================" << endl;


    delete[] encriptado;
    delete[] pista;
    delete[] texto_desencriptado;

    return 0;
}
