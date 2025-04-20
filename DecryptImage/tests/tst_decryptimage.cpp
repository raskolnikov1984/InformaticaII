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
    QString path_info_to_decrypt = "/home/rodia/Escritorio/03-UdeA/InformaticaII/ChallengeI_Requirements/";
    QString case_name = "Caso 1/";
    DecriptImage* decriptImage; // Puntero a la clase a probar
    int steps = 2;
    int heightGenMask = 0;
    int widthGenMask = 0;
    int heightMask = 0;
    int widthMask = 0;
    int heightId = 0;
    int widthId = 0;
    int seed = 0;
    int n_pixeles = 0;

    int widthP1 = 0, heightP1 = 0;
    int widthP2 = 0, heightP2 = 0;

    QString base_path = path_info_to_decrypt + case_name;
    QString idImage = base_path + "I_D.bmp";
    QString maskImage = base_path + "M.bmp";
    QString generalMaskIMage = base_path + "I_M.bmp";
    QString p2Image = "/home/rodia/Escritorio/03-UdeA/InformaticaII/ChallengeI_Requirements/Caso 1/P2.bmp";
    QString p1Image = "/home/rodia/Escritorio/03-UdeA/InformaticaII/ChallengeI_Requirements/Caso 1/P1.bmp";

    unsigned int *maskingData;
    unsigned char *pixelDataGeneralMask = loadPixels(generalMaskIMage, widthGenMask, heightGenMask);
    unsigned char *pixelDataMask = loadPixels(maskImage, widthMask, heightMask);
    unsigned char *pixelDataId = loadPixels(idImage, widthId, heightId);
    unsigned char *pixelDataP2 = loadPixels(p2Image, widthP2, heightP2);
    unsigned char *pixelDataP1 = loadPixels(p1Image, widthP1, heightP1);
    unsigned char *pixelDataBeforeStep;

    void SetUp() override {
        decriptImage = new DecriptImage(path_info_to_decrypt, case_name, 3);
    }

    void TearDown() override {
        delete decriptImage;
    }
};

TEST_F(CaseOneDecryptImage, TestIsXOR){
    // Desenmascarar M2.TXT
    maskingData = loadSeedMasking("/home/rodia/Escritorio/03-UdeA/InformaticaII/ChallengeI_Requirements/Caso 1/M2.txt", seed, n_pixeles);

    EXPECT_EQ(seed, 15);
    EXPECT_EQ(n_pixeles, 100);

    pixelDataBeforeStep = decriptImage->loadPixelsBeforeStep(maskingData, pixelDataMask, n_pixeles * 3);
    unsigned char* result = new unsigned char[n_pixeles];

    int start = seed;
    int end = seed+(n_pixeles*3);
    unsigned char* pixelDataIdRegion = decriptImage->copyRegion(pixelDataId, start, end, widthId, heightId);


    // Se aplica operacion XOR a la Seccion Sin Desenmascarada
    decriptImage->Img1XORImg2(pixelDataBeforeStep, pixelDataGeneralMask, result, n_pixeles);
    EXPECT_EQ(decriptImage->isXOR(result, pixelDataGeneralMask, pixelDataIdRegion, seed, n_pixeles), true);
}

TEST_F(CaseOneDecryptImage, TestIsRotationRight) {
    // Desenmascarar M1.TXT
    int bits = 3;
    maskingData = loadSeedMasking("/home/rodia/Escritorio/03-UdeA/InformaticaII/ChallengeI_Requirements/Caso 1/M1.txt", seed, n_pixeles);

    EXPECT_EQ(seed, 100);
    EXPECT_EQ(n_pixeles, 100);

    pixelDataBeforeStep = decriptImage->loadPixelsBeforeStep(maskingData, pixelDataMask, n_pixeles * 3);

    for(int i=0; i < n_pixeles; i++){
        EXPECT_EQ(decriptImage->rotateRight(pixelDataBeforeStep[i], 3), pixelDataP2[i+100]);
    }
    // EXPECT_EQ(decriptImage->isRotationRight(pixelDataBeforeStep, pixelDataP2, n_pixeles, bits), true);
}

TEST_F(CaseOneDecryptImage, TestDecriptImageCase1){
    QString path_info_to_decrypt = "/home/rodia/Escritorio/03-UdeA/InformaticaII/ChallengeI_Requirements/";
    QString case_name = "Caso 1/";
    int steps = 2;

    bool executed;

    DecriptImage* decriptImage = new DecriptImage(path_info_to_decrypt, case_name, steps);

    executed = decriptImage->Run();

    EXPECT_EQ(executed, true);

    Operation* head = decriptImage->head;
    EXPECT_EQ(head->type, "XOR");
    EXPECT_EQ(head->bits, 0);
    EXPECT_EQ(head->maskFile.toStdString(), "M2.txt");


    Operation* head1 = head->next;
    EXPECT_EQ(head1->type, "RotationRight");
    EXPECT_EQ(head1->bits, 3);

    Operation* head2 = head1->next;
    EXPECT_EQ(head2->type, "XOR");
    EXPECT_EQ(head2->bits, 0);
}
