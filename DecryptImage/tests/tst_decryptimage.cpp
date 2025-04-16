#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <QString>
#include <QDebug>
#include "../tools/provided_tools.h"

using namespace testing;
using namespace std;

TEST(DrecryptImage, DecryptImageTest)
{
    QString archivoEntrada = "/home/rodia/Escritorio/03-UdeA/InformaticaII/ChallengeI_Requirements/Caso 1/I_O.bmp";
    QString archivoSalida = "/home/rodia/Escritorio/03-UdeA/InformaticaII/ChallengeI_Requirements/Caso 1/I_D.bmp";

    int height = 0;
    int width = 0;

    // Paso 1: Cargar la imagen original
    unsigned char *pixelData = loadPixels(archivoEntrada, width, height);

    // Paso 2: Modificar la imagen artificialmente
    for (int i = 0; i < width * height * 3; i += 3) {
        pixelData[i] = i % 256;     // Evitamos desbordamiento usando % 256
        pixelData[i + 1] = i % 256;
        pixelData[i + 2] = i % 256;
    }

    // Paso 3: Exportar la imagen modificada
    bool exportSuccess = exportImage(pixelData, width, height, archivoSalida);
    EXPECT_TRUE(exportSuccess) << "Falló la exportación de la imagen";

    // Liberar memoria de la imagen original
    delete[] pixelData;
    pixelData = nullptr;

    // Paso 4: Cargar datos de enmascaramiento
    int seed = 0;
    int n_pixels = 0;
    unsigned int *maskingData = loadSeedMasking(
        "/home/rodia/Escritorio/03-UdeA/InformaticaII/ChallengeI_Requirements/Caso 1/M1.txt",
        seed,
        n_pixels);

    // Muestra en consola los primeros valores RGB leídos desde el archivo de enmascaramiento
    for (int i = 0; i < n_pixels * 3; i += 3) {
        cout << "Pixel " << i / 3 << ": ("
             << maskingData[i] << ", "
             << maskingData[i + 1] << ", "
             << maskingData[i + 2] << ")" << endl;
    }

    // Libera la memoria usada para los datos de enmascaramiento
    if (maskingData != nullptr){
        delete[] maskingData;
        maskingData = nullptr;
    }
}
