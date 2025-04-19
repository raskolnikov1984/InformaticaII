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
    QString base_path;
    int seed;
    int n_pixeles;
    DecriptImage(const QString& path, const QString& caseName, int steps);
    ~DecriptImage();

    unsigned char* loadPixelsBeforeStep(
        unsigned int* loadSeedMasking, unsigned char* pixelDataMask, int dataSize);

    bool isXOR(unsigned char a, unsigned char b, unsigned char& x);

    bool isShiftLeft(unsigned char a, unsigned char b, int& n);

    bool isShiftRight(unsigned char a, unsigned char b, int& n);

    bool isRotationLeft(unsigned char a, unsigned char b, int& n);

    bool isRotationRight(unsigned char a, unsigned char b, int& n);

    bool Run();

private:
    Operation* head;
    QString idImage;
    QString maskImage;
    int steps;
    void addOperation(const QString& type, int bits);
    void printOperations() const;
};

#endif // DECRIPTIMAGE_H
