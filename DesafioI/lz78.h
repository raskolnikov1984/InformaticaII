#ifndef LZ78_H
#define LZ78_H

void iniciarDiccionario();
void agregarADiccionario(int parent, char ch);
void iniciarSalida();
void agregarASalida(char ch);
void getSequencia(int index, char* sequence, int& seqLength);
bool extraerSiguienteToken(const char* text, int textLength, int& pos, int& index, char& character);
void formatearTokens(const char* compressedText, int textLength, int*& indices, char*& characters, int& tokenCount);
void descomprimirLZ78(const char* compressedText, int textLength);
void imprimirResultado();
void limpiar();
int longitudString(const char* str);
void numeroAString(int numero, char* buffer, int& longitud);
int calcularLongitudTotal(char* desencriptado, int tamano);

#endif // LZ78_H
