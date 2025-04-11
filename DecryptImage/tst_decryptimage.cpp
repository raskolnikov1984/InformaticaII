#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <QString>
#include "./tools/provided_tools.h"

using namespace testing;
using namespace std;

TEST(DrecryptImage, DecryptImage)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}


int main()
{
    // Definición de rutas de archivo de entrada (imagen original) y salida (imagen modificada)
    QString archivoEntrada = "I_O.bmp";
    QString archivoSalida = "I_D.bmp";

    // Variables para almacenar las dimensiones de la imagen
    int height = 0;
    int width = 0;

    // Carga la imagen BMP en memoria dinámica y obtiene ancho y alto
    unsigned char *pixelData = loadPixels(archivoEntrada, width, height);

    // Simula una modificación de la imagen asignando valores RGB incrementales
    // (Esto es solo un ejemplo de manipulación artificial)
    for (int i = 0; i < width * height * 3; i += 3) {
        pixelData[i] = i;     // Canal rojo
        pixelData[i + 1] = i; // Canal verde
        pixelData[i + 2] = i; // Canal azul
    }

    // Exporta la imagen modificada a un nuevo archivo BMP
    bool exportI = exportImage(pixelData, width, height, archivoSalida);

    // Muestra si la exportación fue exitosa (true o false)
    cout << exportI << endl;

    // Libera la memoria usada para los píxeles
    delete[] pixelData;
    pixelData = nullptr;

    // Variables para almacenar la semilla y el número de píxeles leídos del archivo de enmascaramiento
    int seed = 0;
    int n_pixels = 0;

    // Carga los datos de enmascaramiento desde un archivo .txt (semilla + valores RGB)
    unsigned int *maskingData = loadSeedMasking("M1.txt", seed, n_pixels);

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

    return 0; // Fin del programa
}
