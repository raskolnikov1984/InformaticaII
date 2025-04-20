#include "bitwiseoperators.h"

BitWiseOperators::BitWiseOperators() {}

void BitWiseOperators::Img1XORImg2(unsigned char* img1, unsigned char* img2, unsigned char* result, int dataSize){
    for (int i = 0; i < dataSize; ++i) {
        result[i] = img1[i] ^ img2[i+15];
    }
}

unsigned char BitWiseOperators::shiftRight(unsigned char byte, int bits) {
    return byte >> bits;
}

unsigned char BitWiseOperators::shiftLeft(unsigned char byte, int bits) {
    return byte << bits;
}
unsigned char BitWiseOperators::rotateLeft(unsigned char byte, int bits) {
    return (shiftLeft(byte, bits) | shiftRight(byte, 8 - bits));
}

unsigned char BitWiseOperators::rotateRight(unsigned char byte, int bits) {
    return (shiftRight(byte, bits) | shiftLeft(byte, 8 - bits));
}
