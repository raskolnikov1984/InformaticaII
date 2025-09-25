#include <iostream>
#include "encriptacion.h"
#include "files.h"

using namespace std;

int main()
{
    const char archivo_encriptado[] = "/home/rodia/Desktop/DesafioI/dataset/Encriptado1.txt";
    const char archivo_pista[] = "/home/rodia/Desktop/DesafioI/dataset/pista1.txt";

    const char* encriptado = leerArchivo(archivo_encriptado);
    const char* pista = leerArchivo(archivo_pista);
    int tamano = calcularTamanoArchivo(archivo_encriptado);

    int metodo, n_out, K_out;

    char* texto_desencriptado;

    metodo = detectarMetodoYParametros(
        encriptado, tamano, pista, n_out, K_out, texto_desencriptado);

    cout << "TEXTO DESENCRIPTADO" << endl;
    cout << "=======================================" << endl;
    cout << texto_desencriptado << endl;
    cout << "=======================================" << endl;
    cout << "Metodo: " << metodo << endl;
    cout << "n OUT: " << n_out << endl;
    cout << "K out: " << K_out << endl;;
    cout << "=======================================" << endl;


    delete[] encriptado;
    delete[] pista;
    delete[] texto_desencriptado;

    return 0;
}
