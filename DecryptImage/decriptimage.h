#ifndef DECRIPTIMAGE_H
#define DECRIPTIMAGE_H

class DecriptImage
{
public:
    DecriptImage();

    unsigned char* loadPixelsBeforeStep(
        unsigned int* loadSeedMasking, unsigned char* pixelDataMask, int dataSize);
};

#endif // DECRIPTIMAGE_H
