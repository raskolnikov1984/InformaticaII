#ifndef DECRIPTIMAGE_H
#define DECRIPTIMAGE_H
#include "bitwiseoperators.h"

class DecriptImage : public BitWiseOperators
{
public:
    DecriptImage();

    unsigned char* loadPixelsBeforeStep(
        unsigned int* loadSeedMasking, unsigned char* pixelDataMask, int dataSize);

    bool isXOR(unsigned char a, unsigned char b, unsigned char& x);

    bool isShiftLeft(unsigned char a, unsigned char b, int& n);

    bool isShiftRight(unsigned char a, unsigned char b, int& n);

    bool isRotationLeft(unsigned char a, unsigned char b, int& n);

    bool isRotationRight(unsigned char a, unsigned char b, int& n);
};

#endif // DECRIPTIMAGE_H
