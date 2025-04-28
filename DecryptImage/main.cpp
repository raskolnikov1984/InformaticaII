#include <QCoreApplication>
#include "decriptimage.h"
#include "tools/provided_tools.h"
#include <QString>

using namespace std;


int main(){
    QString path_info_to_decrypt = "/home/rodia/Escritorio/03-UdeA/InformaticaII/ChallengeI_Requirements/";
    QString case_name = "Caso 2/";
    QString base_path = path_info_to_decrypt + case_name;
    int steps = 6;

    DecriptImage* decriptImage = new DecriptImage(path_info_to_decrypt, case_name, steps);
    decriptImage->Run();

    return 0;
}
