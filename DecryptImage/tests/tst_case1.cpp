#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "../bitwiseoperators.h"
#include "../tools/provided_tools.h"
#include <QString>
#include <QDebug>

using namespace testing;

class CaseOne : public ::testing::Test {
public:
    BitWiseOperators bitwiseOperators;
    QString originalImage = "/home/rodia/Escritorio/03-UdeA/InformaticaII/ChallengeI_Requirements/Caso 1/I_O.bmp";
    QString maskImage = "/home/rodia/Escritorio/03-UdeA/InformaticaII/ChallengeI_Requirements/Caso 1/I_M.bmp";
    QString p1Image = "/home/rodia/Escritorio/03-UdeA/InformaticaII/ChallengeI_Requirements/Caso 1/P1.bmp";
    QString p2Image = "/home/rodia/Escritorio/03-UdeA/InformaticaII/ChallengeI_Requirements/Caso 1/P2.bmp";

    int heightI_O = 0, heightI_M = 0;
    int widthI_O = 0, widthI_M = 0;

    unsigned char *pixelDataI_O = loadPixels(originalImage, widthI_O, heightI_O);
    int dataSize = heightI_O * widthI_O * 3;

    unsigned char *pixelDataI_M = loadPixels(maskImage, widthI_M, heightI_M);
    unsigned char *pixelDataResult = new unsigned char[dataSize];
};


TEST_F(CaseOne, Case1Test){
    EXPECT_EQ(heightI_O, 225);
    EXPECT_EQ(widthI_O, 225);
    EXPECT_EQ(*(pixelDataI_O), 255);
    EXPECT_EQ(*(pixelDataI_O + 151874), 255);
    EXPECT_EQ(dataSize, 151875);
}

TEST_F(CaseOne, CaseOneXOROperationTest){
    int widthP1 = 0;
    int heightP1 = 0;
    unsigned char *pixelDataP1 = loadPixels(p1Image, widthP1, heightP1);
    bitwiseOperators.XOR(pixelDataI_O, pixelDataI_M, pixelDataResult, dataSize);
    for (int i = 0; i < dataSize; ++i) {
        EXPECT_EQ(pixelDataResult[i], pixelDataP1[i]);
    }
}
