#ifndef DECRIPTIMAGE_H
#define DECRIPTIMAGE_H
#include "bitwiseoperators.h"
#include <QString>

using namespace std;

struct Operation {
    QString type;
    int bits;
    QString maskFile;
    Operation* next;
};

enum OperationTypes {
    XOR = 1,
    RotationRight,
    RotationLeft,
    ShiftRight,
    ShiftLeft
};


class DecriptImage : public BitWiseOperators
{
public:
    QString base_path;
    QString maskFile;
    Operation* head;
    unsigned char* pixelDataId;
    unsigned char* pixelDataGeneralMask;
    unsigned char* pixelDataMask;

    int widthId;
    int heigthId;
    int widthGm;
    int heigthGm;
    int widthM;
    int heigthM;
    int seed;
    int n_pixeles;
    int operations;

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

    unsigned char* copyRegion(
        unsigned char* pixelData, int start, int end,int width, int height);

    unsigned char* decriptRegion(
        unsigned char* pixelData, unsigned char* pixelDataGeneralMaskRegion, OperationTypes operationType, int& dataSize, int width, int height, int& seed, int& bits);

    unsigned char* decriptIdImage(
        unsigned char* pixelDataIdRegion, unsigned char* pixelDataGeneralMaskRegion, int& width, int& heigth);
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
