#include "decriptimage.h"

DecriptImage::DecriptImage() {}

unsigned char* DecriptImage::loadPixelsBeforeStep(unsigned int* loadSeedMasking, unsigned char* pixelDataMask, int dataSize){
    unsigned char* pixelData = new unsigned char[dataSize];

    for(int i=0; i < dataSize; i++){
        pixelData[i] = loadSeedMasking[i] - pixelDataMask[i];
    }

    return pixelData;
}
