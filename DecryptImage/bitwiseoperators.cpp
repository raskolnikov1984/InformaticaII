#include "bitwiseoperators.h"

BitWiseOperators::BitWiseOperators() {}

void BitWiseOperators::XOR(unsigned char* img1, unsigned char* img2, unsigned char* result, int dataSize){
    for (int i = 0; i < dataSize; ++i) {
        result[i] = img1[i] ^ img2[i];
    }
}
