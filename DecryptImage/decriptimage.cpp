#include "decriptimage.h"

DecriptImage::DecriptImage() {
}

DecriptImage::~DecriptImage() {
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
    this->addOperation("XOR", 0);
    return true;
}

bool DecriptImage::isRotationLeft(unsigned char a, unsigned char b, int& n) {
    for (n = 1; n < 8; ++n) {
        if (rotateLeft(a, n) == b)
            this->addOperation("Rotation Left", 0);
            return true;
    }
    return false;
}

bool DecriptImage::isRotationRight(unsigned char a, unsigned char b, int& n) {
    for (n = 1; n < 8; ++n) {
        if (rotateRight(a, n) == b)
            this->addOperation("Rotation Right", n);
            return true;
    }
    return false;
}

bool DecriptImage::isShiftRight(unsigned char a, unsigned char b, int& n) {
    for (n = 1; n < 8; ++n) {
        if (shiftRight(a, n) == b)
            this->addOperation("Shift Right", n);
            return true;
    }
    return false;
}

bool DecriptImage::isShiftLeft(unsigned char a, unsigned char b, int& n) {
    for (n = 1; n < 8; ++n) {
        if (shiftLeft(a, n) == b)
            this->addOperation("Shift Left", n);
            return true;
    }
    return false;
}

void DecriptImage::addOperation(const string& type, int bits) {
    Operation* newOperation = new Operation;
    newOperation->type = type;
    newOperation->bits = bits;
    newOperation->next = head;
    head = newOperation;
}
