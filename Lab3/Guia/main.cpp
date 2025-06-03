#include <gtest/gtest.h>
#include "methods.h"


int main(int argc, char *argv[])
{
    int option;
    cout << "Seleccione una opción:\n1. Codificar archivo\n2. Decodificar archivo\n> ";
    cin >> option;

    if (option == 1) {
        string inputFile, outputFile;
        int n, method;

        cout << "Archivo de texto a codificar: ";
        cin >> inputFile;
        cout << "Archivo de salida binaria: ";
        cin >> outputFile;
        cout << "Semilla (n): ";
        cin >> n;
        cout << "Método (1 o 2): ";
        cin >> method;

        ifstream in(inputFile, ios::binary | ios::ate);
        if (!in) {
            cerr << "No se pudo abrir el archivo de entrada.\n";
            return 1;
        }

        int length = in.tellg();
        in.seekg(0);
        char* buffer = new char[length];
        in.read(buffer, length);
        in.close();

        string bin = textToBinary(buffer, length);
        delete[] buffer;

        string encoded;
        if (method == 1)
            encoded = encodeMethod1(bin, n);
        else if (method == 2)
            encoded = encodeMethod2(bin, n);
        else {
            cerr << "Método inválido.\n";
            return 1;
        }

        writeBinaryFile(encoded, outputFile);
        cout << "Archivo codificado correctamente.\n";

    } else if (option == 2) {
        string inputFile, outputFile;
        int n, method;

        cout << "Archivo binario a decodificar: ";
        cin >> inputFile;
        cout << "Archivo de salida de texto: ";
        cin >> outputFile;
        cout << "Semilla (n): ";
        cin >> n;
        cout << "Método usado para codificar (1 o 2): ";
        cin >> method;

        string encodedBin = readBinaryFile(inputFile);
        if (encodedBin.empty()) return 1;

        string decodedBin;
        if (method == 1)
            decodedBin = decodeMethod1(encodedBin, n);
        else if (method == 2)
            decodedBin = decodeMethod2(encodedBin, n);
        else {
            cerr << "Método inválido.\n";
            return 1;
        }

        string text = binaryToText(decodedBin);

        ofstream out(outputFile, ios::binary);
        if (!out) {
            cerr << "No se pudo crear el archivo de salida.\n";
            return 1;
        }

        out.write(text.c_str(), text.size());
        out.close();

        cout << "Archivo decodificado correctamente.\n";
    } else {
        cerr << "Opción inválida.\n";
        return 1;
    }

    return 0;
}
