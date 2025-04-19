#ifndef BITWISEOPERATORS_H
#define BITWISEOPERATORS_H

class BitWiseOperators
{
public:
    BitWiseOperators();

    void Img1XORImg2(unsigned char* img1, unsigned char* img2, unsigned char* result, int dataSize);

    unsigned char shiftLeft(unsigned char byte, int bits);

    unsigned char shiftRight(unsigned char byte, int bits);

    unsigned char rotateLeft(unsigned char byte, int bits);

    unsigned char rotateRight(unsigned char byte, int bits);

};

#endif // BITWISEOPERATORS_H
