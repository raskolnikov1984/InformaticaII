#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <QString>
#include <QDebug>
#include "../tools/provided_tools.h"
#include "../decriptimage.h"

using namespace testing;
using namespace std;


class CaseOneDecryptImage : public ::testing::Test {
public:

    DecriptImage decriptImage;
    QString path_info_to_decrypt = "/home/rodia/Escritorio/03-UdeA/InformaticaII/ChallengeI_Requirements/";
    QString case_name = "Caso 1/";
    QString base_path = path_info_to_decrypt + case_name;
    QString idImage = base_path + "I_D.bmp";
    QString maskImage = base_path + "M.bmp";
    QString p2Image = "/home/rodia/Escritorio/03-UdeA/InformaticaII/ChallengeI_Requirements/Caso 1/P2.bmp";
    QString p1Image = "/home/rodia/Escritorio/03-UdeA/InformaticaII/ChallengeI_Requirements/Caso 1/P1.bmp";

    int steps = 2;

    int heightMask = 0;
    int widthMask = 0;
    int seed = 0;
    int n_pixeles = 0;

    int widthP1 = 0, heightP1 = 0;
    int widthP2 = 0, heightP2 = 0;

    unsigned int *maskingData = loadSeedMasking("/home/rodia/Escritorio/03-UdeA/InformaticaII/ChallengeI_Requirements/Caso 1/M2.txt", seed, n_pixeles);
    unsigned char *pixelDataMask = loadPixels(maskImage, widthMask, heightMask);
    unsigned char *pixelDataP2 = loadPixels(p2Image, widthP2, heightP2);
    unsigned char *pixelDataP1 = loadPixels(p1Image, widthP1, heightP1);

};

TEST_F(CaseOneDecryptImage, CaseOneDecryptImageTest){
    EXPECT_EQ(seed, 15);
    EXPECT_EQ(n_pixeles, 100);

    unsigned char *pixelDataBeforeStep = decriptImage.loadPixelsBeforeStep(
        maskingData, pixelDataMask, n_pixeles * 3);
    for(int i=0; i < n_pixeles * 3; i++){
        EXPECT_EQ(pixelDataBeforeStep[i], pixelDataP2[i+seed]);
    }
}

TEST_F(CaseOneDecryptImage, TestIsXOR) {
    unsigned char a = 0b10101010;
    unsigned char b = 0b01010101;
    unsigned char result;

    EXPECT_TRUE(decriptImage.isXOR(a, b, result));
    EXPECT_EQ(result, a ^ b);
}

TEST_F(CaseOneDecryptImage, TestIsRotationLeft) {
    unsigned char a = 0b00000001; // 1
    unsigned char b = 0b00000010; // 2
    int n;

    EXPECT_TRUE(decriptImage.isRotationLeft(a, b, n));
    EXPECT_EQ(n, 1); // Debe ser 1 porque 1 rotado a la izquierda 1 bit es 2
}

TEST_F(CaseOneDecryptImage, TestIsRotationRight) {
    unsigned char a = 0b00000010; // 2
    unsigned char b = 0b00000001; // 1
    int n;

    EXPECT_TRUE(decriptImage.isRotationRight(a, b, n));
    EXPECT_EQ(n, 1); // Debe ser 1 porque 2 rotado a la derecha 1 bit es 1
}

TEST_F(CaseOneDecryptImage, TestIsShiftRight) {
    unsigned char a = 0b00000100; // 4
    unsigned char b = 0b00000010; // 2
    int n;

    EXPECT_TRUE(decriptImage.isShiftRight(a, b, n));
    EXPECT_EQ(n, 1); // Debe ser 1 porque 4 desplazado a la derecha 1 bit es 2
}

TEST_F(CaseOneDecryptImage, TestIsShiftLeft) {
    unsigned char a = 0b00000010; // 2
    unsigned char b = 0b00000100; // 4
    int n;

    EXPECT_TRUE(decriptImage.isShiftLeft(a, b, n));
    EXPECT_EQ(n, 1); // Debe ser 1 porque 2 desplazado a la izquierda 1 bit es 4
}
