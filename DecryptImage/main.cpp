#include <QCoreApplication>
#include "decriptimage.h"
#include <QString>
#include <QDebug>

using namespace std;


int main(){
    QString path_info_to_decrypt = "/home/rodia/Escritorio/03-UdeA/InformaticaII/ChallengeI_Requirements/";
    QString case_name = "Caso 1/";
    int steps = 2;

    bool executed;

    DecriptImage* decriptImage = new DecriptImage(path_info_to_decrypt, case_name, steps);

    decriptImage->Run();
    delete decriptImage;

    return 0;
}
