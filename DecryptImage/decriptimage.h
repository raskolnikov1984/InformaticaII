#ifndef DECRIPTIMAGE_H
#define DECRIPTIMAGE_H
#include "bitwiseoperators.h"
#include <string>
#include <QString>

using namespace std;

struct Operation {
    QString type;
    int bits;
    Operation* next;
};

class DecriptImage : public BitWiseOperators
{
public:
    DecriptImage();
    ~DecriptImage();

    unsigned char* loadPixelsBeforeStep(
        unsigned int* loadSeedMasking, unsigned char* pixelDataMask, int dataSize);

    bool isXOR(unsigned char a, unsigned char b, unsigned char& x);

    bool isShiftLeft(unsigned char a, unsigned char b, int& n);

    bool isShiftRight(unsigned char a, unsigned char b, int& n);

    bool isRotationLeft(unsigned char a, unsigned char b, int& n);

    bool isRotationRight(unsigned char a, unsigned char b, int& n);

private:
    Operation* head;
    void addOperation(const QString& type, int bits);
};

#endif // DECRIPTIMAGE_H
