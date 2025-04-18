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
