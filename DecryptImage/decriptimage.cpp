#include "decriptimage.h"
#include "bitwiseoperators.h"

DecriptImage::DecriptImage() {
    BitWiseOperators bitwiseOperators;
}

unsigned char* DecriptImage::loadPixelsBeforeStep(unsigned int* loadSeedMasking, unsigned char* pixelDataMask, int dataSize){
    unsigned char* pixelData = new unsigned char[dataSize];

    for(int i=0; i < dataSize; i++){
        pixelData[i] = loadSeedMasking[i] - pixelDataMask[i];
    }

    return pixelData;
}


bool DecriptImage::isXOR(unsigned char a, unsigned char b, unsigned char& x) {
    x = a ^ b;
    return true;
}

bool DecriptImage::isRotationLeft(unsigned char a, unsigned char b, int& n) {
    for (n = 1; n < 8; ++n) {
        if (((a >> n) | (a << (8 - n))) & 0xFF == b)
            return true;
    }
    return false;
}

bool DecriptImage::isRotationRight(unsigned char a, unsigned char b, int& n) {
    for (n = 1; n < 8; ++n) {
        if (((a >> n) | (a << (8 - n))) & 0xFF == b)
            return true;
    }
    return false;
}

bool DecriptImage::isShiftRight(unsigned char a, unsigned char b, int& n) {
    for (n = 1; n < 8; ++n) {
        if ((a >> n) == b)
            return true;
    }
    return false;
}

bool DecriptImage::isShiftLeft(unsigned char a, unsigned char b, int& n) {
    for (n = 1; n < 8; ++n) {
        if ((a >> n) == b)
            return true;
    }
    return false;
}
