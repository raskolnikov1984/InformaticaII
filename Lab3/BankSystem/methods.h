#ifndef METHODS_H
#define METHODS_H

#include <iostream>
#include <fstream>
#include <bitset>
#include <string>

using namespace std;

// Convierte todo el texto a una cadena binaria usando bitset
string textToBinary(const char* text, int length) {
    string binary;
    for (int i = 0; i < length; ++i) {
        bitset<8> b((unsigned char)text[i]);
        binary += b.to_string();  // 8 bits por carácter
    }
    return binary;
}

// Codifica con el Método 1
string encodeMethod1(const string& bin, int n) {
    int totalBits = bin.length();
    int numBlocks = (totalBits + n - 1) / n;
    string result = bin;

    for (int i = 0; i < numBlocks; ++i) {
        int start = i * n;
        int end = (start + n < totalBits) ? start + n : totalBits;

        // Extraer bloque actual
        string block = bin.substr(start, end - start);

        if (i == 0) {
            // Invertir todos los bits
            for (int j = 0; j < block.length(); ++j)
                result[start + j] = (block[j] == '1') ? '0' : '1';
        } else {
            // Contar 1s y 0s en el bloque anterior
            int prevStart = (i - 1) * n;
            int prevEnd = (prevStart + n < totalBits) ? prevStart + n : totalBits;
            string prevBlock = bin.substr(prevStart, prevEnd - prevStart);

            int ones = 0, zeros = 0;
            for (char c : prevBlock) {
                if (c == '1') ++ones;
                else ++zeros;
            }

            // Copiar bloque sin modificar
            for (int j = 0; j < block.length(); ++j)
                result[start + j] = block[j];

            // Aplicar transformación
            if (ones == zeros) {
                for (int j = 0; j < block.length(); ++j)
                    result[start + j] = (block[j] == '1') ? '0' : '1';
            } else if (zeros > ones) {
                for (int j = 0; j + 1 < block.length(); j += 2)
                    swap(result[start + j], result[start + j + 1]);
            } else {
                for (int j = 0; j + 2 < block.length(); j += 3)
                    swap(result[start + j], result[start + j + 2]);
            }
        }
    }

    return result;
}

// Codifica con el Método 2 (desplazamiento circular a la derecha en cada bloque)
string encodeMethod2(const string& bin, int n) {
    int totalBits = bin.length();
    int numBlocks = (totalBits + n - 1) / n;
    string result = bin;

    for (int i = 0; i < numBlocks; ++i) {
        int start = i * n;
        int end = (start + n < totalBits) ? start + n : totalBits;
        int len = end - start;

        for (int j = 0; j < len; ++j) {
            result[start + ((j + 1) % len)] = bin[start + j];
        }
    }

    return result;
}

// Escribe la cadena binaria como archivo binario real
void writeBinaryFile(const string& bin, const string& outputFilename) {
    ofstream out(outputFilename, ios::binary);
    if (!out) {
        cerr << "No se pudo abrir el archivo de salida.\n";
        return;
    }

    for (size_t i = 0; i < bin.size(); i += 8) {
        string byteStr = bin.substr(i, 8);
        while (byteStr.length() < 8) byteStr += '0'; // Padding
        bitset<8> byte(byteStr);
        unsigned char c = static_cast<unsigned char>(byte.to_ulong());
        out.write((char*)&c, 1);
    }

    out.close();
}


// Convierte bytes binarios a cadena de bits
string readBinaryFile(const string& filename) {
    ifstream in(filename, ios::binary);
    if (!in) {
        cerr << "No se pudo abrir el archivo binario.\n";
        return "";
    }

    string binary;
    char byte;
    while (in.read(&byte, 1)) {
        bitset<8> b((unsigned char)byte);
        binary += b.to_string();
    }

    in.close();
    return binary;
}

// Decodifica con el Método 1 (inverso del método 1 de codificación)
string decodeMethod1(const string& bin, int n) {
    int totalBits = bin.length();
    int numBlocks = (totalBits + n - 1) / n;
    string result = bin;

    for (int i = 0; i < numBlocks; ++i) {
        int start = i * n;
        int end = (start + n < totalBits) ? start + n : totalBits;

        string block = bin.substr(start, end - start);

        if (i == 0) {
            for (int j = 0; j < block.length(); ++j)
                result[start + j] = (block[j] == '1') ? '0' : '1';
        } else {
            int prevStart = (i - 1) * n;
            int prevEnd = (prevStart + n < totalBits) ? prevStart + n : totalBits;
            string prevBlock = result.substr(prevStart, prevEnd - prevStart); // usar ya decodificado

            int ones = 0, zeros = 0;
            for (char c : prevBlock) {
                if (c == '1') ++ones;
                else ++zeros;
            }

            for (int j = 0; j < block.length(); ++j)
                result[start + j] = block[j]; // copiar sin modificar aún

            if (ones == zeros) {
                for (int j = 0; j < block.length(); ++j)
                    result[start + j] = (block[j] == '1') ? '0' : '1';
            } else if (zeros > ones) {
                for (int j = 0; j + 1 < block.length(); j += 2)
                    swap(result[start + j], result[start + j + 1]);
            } else {
                for (int j = 0; j + 2 < block.length(); j += 3)
                    swap(result[start + j], result[start + j + 2]);
            }
        }
    }

    return result;
}

// Decodifica con el Método 2 (inverso del desplazamiento circular)
string decodeMethod2(const string& bin, int n) {
    int totalBits = bin.length();
    int numBlocks = (totalBits + n - 1) / n;
    string result = bin;

    for (int i = 0; i < numBlocks; ++i) {
        int start = i * n;
        int end = (start + n < totalBits) ? start + n : totalBits;
        int len = end - start;

        for (int j = 0; j < len; ++j) {
            result[start + j] = bin[start + ((j - 1 + len) % len)];
        }
    }

    return result;
}

// Convierte binario a texto
string binaryToText(const string& bin) {
    string text;
    for (size_t i = 0; i + 8 <= bin.length(); i += 8) {
        bitset<8> b(bin.substr(i, 8));
        text += static_cast<char>(b.to_ulong());
    }
    return text;
}

#endif // METHODS_H
