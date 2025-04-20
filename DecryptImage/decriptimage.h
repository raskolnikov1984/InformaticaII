#ifndef DECRIPTIMAGE_H
#define DECRIPTIMAGE_H
#include "bitwiseoperators.h"
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
    QString base_path;
    int seed;
    int n_pixeles;
    Operation* head;

    DecriptImage(const QString& path, const QString& caseName, int steps);
    ~DecriptImage();

    unsigned char* loadPixelsBeforeStep(
        unsigned int* loadSeedMasking, unsigned char* pixelDataMask, int dataSize);

    bool isXOR(unsigned char* img, unsigned char* generalMask, unsigned char* imgId, int& seed, int &n_pixels);

    bool isShiftLeft(unsigned char* img, unsigned char* imgId, int& n_pixels, int& bits);

    bool isShiftRight(unsigned char* img, unsigned char* imgId, int& n_pixels, int& bits);

    bool isRotationLeft(unsigned char* img, unsigned char* imgId, int& n_pixels, int& bits);

    bool isRotationRight(unsigned char* img, unsigned char* imgId, int& n_pixels, int& bits);

    bool detectTransform(
        unsigned char* pixelBefore, unsigned char* pixelDataGeneralMask, unsigned char* pixelDataId, int& seed, int& n_pixels);

    unsigned char* copyRegion(unsigned char* pixelData, int start, int end,int width, int height);

    bool Run();

private:
    QString idImage;
    QString maskImage;
    QString generalMask;
    int steps;
    void addOperation(const QString& type, int bits);
    void printOperations() const;
};

#endif // DECRIPTIMAGE_H
