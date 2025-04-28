#include <QCoreApplication>
#include "decriptimage.h"
#include <QString>
#include <iostream>

using namespace std;


int main(){
    QString path_info_to_decrypt = "/home/rodia/Escritorio/03-UdeA/InformaticaII/ChallengeI_Requirements/";
    QString case_name;
    int case_number = 0;
    int steps = 0;

    do{
        cout << "Por favor ingrese el numero del caso";
        cin >> case_number;
    } while(case_number != 1 && case_number != 2);


    switch (case_number) {
    case 1:
        case_name = "Caso 1/";
        steps = 2;
        break;
    case 2:
        case_name = "Caso 2/";
        steps = 6;
        break;
    default:
        break;
    }

    DecriptImage* decriptImage = new DecriptImage(path_info_to_decrypt, case_name, steps);
    decriptImage->Run();

    return 0;
}
