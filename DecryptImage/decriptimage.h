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

struct OperationTypesStruct {
    static const int XOR = 1;
    static const int RotationRight = 2;
    static const int RotationLeft = 3;
    static const int ShiftRight = 4;
    static const int ShiftLeft = 5;
};

class DecriptImage : public BitWiseOperators
{
public:
    QString base_path;
    QString maskFile;
    Operation* head;
    unsigned char* pixelDataId;

    int widthId;
    int height;
    int seed;
    int n_pixeles;

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

    unsigned char* decriptRegion(
        unsigned char* pixelData,
        OperationTypes operationType,
        int& dataSize,
        int width,
        int height,
        int& seed,
        int& bits);

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
