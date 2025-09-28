#include "lz78.h"
#include <iostream>

using namespace std;

struct NodoDiccionario {
    int parent;
    char character;
};

NodoDiccionario* diccionario = nullptr;
int tamanoDiccionario    = 0;
int capacidadDiccionario = 0;

char* salida = nullptr;
int tamanoSalida = 0;
int capacidadSalida = 0;

void iniciarDiccionario() {
    capacidadDiccionario = 1000;
    diccionario = new NodoDiccionario[capacidadDiccionario];
    tamanoDiccionario = 0;

    diccionario[0].parent = -1;
    diccionario[0].character = '\0';
    tamanoDiccionario = 1;
}

void agregarADiccionario(int parent, char ch) {
    if (tamanoDiccionario >= capacidadDiccionario) {
        int newCapacity = capacidadDiccionario * 2;
        NodoDiccionario* newDict = new NodoDiccionario[newCapacity];

        for (int i = 0; i < tamanoDiccionario; i++) {
            newDict[i] = diccionario[i];
        }

        delete[] diccionario;
        diccionario = newDict;
        capacidadDiccionario = newCapacity;
    }

    diccionario[tamanoDiccionario].parent = parent;
    diccionario[tamanoDiccionario].character = ch;
    tamanoDiccionario++;
}

void iniciarSalida() {
    capacidadSalida = 10000;
    salida = new char[capacidadSalida];
    tamanoSalida = 0;
}

void agregarASalida(char ch) {
    if (tamanoSalida >= capacidadSalida) {
        int newCapacity = capacidadSalida * 2;
        char* newOutput = new char[newCapacity];

        for (int i = 0; i < tamanoSalida; i++) {
            newOutput[i] = salida[i];
        }

        delete[] salida;
        salida = newOutput;
        capacidadSalida = newCapacity;
    }

    salida[tamanoSalida] = ch;
    tamanoSalida++;
}

void getSequencia(int index, char* sequence, int& seqLength) {
    seqLength = 0;

    if (index == 0) return;

    char tempSeq[1000];
    int tempLength = 0;
    int current = index;

    while (current > 0 && current < tamanoDiccionario) {
        tempSeq[tempLength] = diccionario[current].character;
        tempLength++;
        current = diccionario[current].parent;
    }

    for (int i = tempLength - 1; i >= 0; i--) {
        sequence[seqLength] = tempSeq[i];
        seqLength++;
    }
}

bool extraerSiguienteToken(const char* text, int textLength, int& pos, int& index, char& character) {
    while (pos < textLength && (text[pos] < '0' || text[pos] > '9')) {
        pos++;
    }

    if (pos >= textLength) return false;

    index = 0;
    int digitStart = pos;

    while (pos < textLength && text[pos] >= '0' && text[pos] <= '9') {
        index = index * 10 + (text[pos] - '0');
        pos++;
    }

    if (pos == digitStart) return false;

    if (pos >= textLength || text[pos] < 'a' || text[pos] > 'z') {
        return false;
    }

    character = text[pos];
    pos++;

    return true;
}

void formatearTokens(const char* compressedText, int textLength, int*& indices, char*& characters, int& tokenCount) {
    tokenCount = 0;
    int pos = 0;
    int tempIndex;
    char tempChar;

    while (extraerSiguienteToken(compressedText, textLength, pos, tempIndex, tempChar)) {
        tokenCount++;
    }

    indices = new int[tokenCount];
    characters = new char[tokenCount];

    pos = 0;
    int i = 0;
    while (extraerSiguienteToken(compressedText, textLength, pos, indices[i], characters[i])) {
        i++;
    }
}

void descomprimirLZ78(const char* compressedText, int textLength) {
    iniciarDiccionario();
    iniciarSalida();

    int* indices;
    char* characters;
    int tokenCount;

    formatearTokens(compressedText, textLength, indices, characters, tokenCount);

    for (int i = 0; i < tokenCount; i++) {
        int dictIndex = indices[i];
        char nextChar = characters[i];

        if (dictIndex >= tamanoDiccionario) {
            cout << "Error en token " << i << ": Índice " << dictIndex
                 << " inválido (dict size: " << tamanoDiccionario << ")" << endl;
            break;
        }

        char sequence[1000];
        int seqLength;
        getSequencia(dictIndex, sequence, seqLength);

        for (int j = 0; j < seqLength; j++) {
            agregarASalida(sequence[j]);
        }

        agregarASalida(nextChar);
        agregarADiccionario(dictIndex, nextChar);
    }

    delete[] indices;
    delete[] characters;
}

void imprimirResultado() {
    cout << "\nTexto descomprimido:" << endl;
    cout << "================================================" << endl;
    for (int i = 0; i < tamanoSalida; i++) {
        cout << salida[i];
    }
    cout << endl;
    cout << "================================================" << endl;
}

void limpiar() {
    delete[] diccionario;
    delete[] salida;
}

int longitudString(const char* str) {
    int longitud = 0;
    while (str[longitud] != '\0') {
        longitud++;
    }
    return longitud;
}


void numeroAString(int numero, char* buffer, int& longitud) {
    longitud = 0;
    if (numero == 0) {
        buffer[0] = '0';
        longitud = 1;
        return;
    }

    int temp = numero;
    int digits = 0;
    while (temp > 0) {
        temp /= 10;
        digits++;
    }

    longitud = digits;
    for (int i = digits - 1; i >= 0; i--) {
        buffer[i] = '0' + (numero % 10);
        numero /= 10;
    }
}

int calcularLongitudTotal(char* desencriptado, int tamano) {
    int longitud_total = 0;
    int numTernas = tamano / 3;

    for (int i = 0; i < numTernas; i++) {
        int pos = i * 3;
        int numero = abs(int(desencriptado[pos]) << 8 | int(desencriptado[pos + 1]));

        if (numero == 0) {
            longitud_total += 1;
        } else {
            int temp = numero;
            while (temp > 0) {
                temp /= 10;
                longitud_total++;
            }
        }
        longitud_total += 1;
    }

    return longitud_total;
}

