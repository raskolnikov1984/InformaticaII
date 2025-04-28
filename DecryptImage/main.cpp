#include <QCoreApplication>
#include "decriptimage.h"
#include "tools/provided_tools.h"
#include <QString>
#include <QDebug>

using namespace std;


int main(){
    QString path_info_to_decrypt = "/home/rodia/Escritorio/03-UdeA/InformaticaII/ChallengeI_Requirements/";
    QString case_name = "Caso 1/";
    QString base_path = path_info_to_decrypt + case_name;
    int steps = 2;

    DecriptImage* decriptImage = new DecriptImage(path_info_to_decrypt, case_name, steps);
    //decriptImage->Run();


    // int width;
    // int heigth;


    // unsigned char* ioImage = loadPixels(base_path+"I_O.bmp", width, heigth);
    // unsigned char* idImage = loadPixels(base_path+"I_D.bmp", width, heigth);
    // unsigned char* mgImage = loadPixels(base_path+"I_M.bmp", width, heigth);
    // unsigned char* p2Image = loadPixels(base_path+"P2.bmp", width, heigth);
    // unsigned char* p1Image = loadPixels(base_path+"P1.bmp", width, heigth);
    // int dataSize = (width * heigth * 3);
    // unsigned char* result = new unsigned char[dataSize];
    // bool pixelsEqual;


    // decriptImage->Img1XORImg2(idImage, mgImage, result, dataSize);


    // for(int i=0; i<dataSize;i++){
    //     result[i] = decriptImage->rotateLeft(result[i], 3);
    //     pixelsEqual = decriptImage->rotateLeft(result[i], 3) == p1Image[i];
    // }





    // decriptImage->Img1XORImg2(result, mgImage, result, dataSize);

    // for(int i=0; i<dataSize;i++){
    //     pixelsEqual = result[i] == ioImage[i];
    // }

    // exportImage(result, width, heigth, "/home/rodia/Escritorio/03-UdeA/InformaticaII/DecryptImage/Output/EstaSieslaEsperadoa.bmp");

    // delete[] idImage;
    // delete[] mgImage;
    // delete[] p2Image;
    // delete[] result;

    delete decriptImage;

    return 0;
}
