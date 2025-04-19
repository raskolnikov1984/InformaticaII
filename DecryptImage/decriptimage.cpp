#include "decriptimage.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include "tools/provided_tools.h"


using namespace std;

DecriptImage::DecriptImage(const QString& path, const QString& caseName, int steps) : head(nullptr), steps(steps) {
    base_path = path + caseName;
    idImage = base_path + "I_D.bmp";
    maskImage = base_path + "M.bmp";
    int seed = 0;
    int n_pixeles = 0;
}

DecriptImage::~DecriptImage() {
}

unsigned char* DecriptImage::loadPixelsBeforeStep(unsigned int* loadSeedMasking, unsigned char* pixelDataMask, int dataSize){
    unsigned char* pixelData = new unsigned char[dataSize];

    for(int i=0; i < dataSize; i++){
        pixelData[i] = loadSeedMasking[i] - pixelDataMask[i];
    }

    return pixelData;
}


bool DecriptImage::isXOR(unsigned char a, unsigned char b, unsigned char& x) {
    x = a ^ b;
    if((x & 0xFF) < 256){
        this->addOperation("XOR", x);
        return true;
    }
    return false;
}

bool DecriptImage::isRotationLeft(unsigned char a, unsigned char b, int& n) {
    for (n = 1; n < 8; ++n) {
        if (rotateLeft(a, n) == b)
            this->addOperation("Rotation Left", n);
            return true;
    }
    return false;
}

bool DecriptImage::isRotationRight(unsigned char a, unsigned char b, int& n) {
    for (n = 1; n < 8; ++n) {
        if (rotateRight(a, n) == b)
            this->addOperation("Rotation Right", n);
            return true;
    }
    return false;
}

bool DecriptImage::isShiftRight(unsigned char a, unsigned char b, int& n) {
    for (n = 1; n < 8; ++n) {
        if (shiftRight(a, n) == b)
            this->addOperation("Shift Right", n);
            return true;
    }
    return false;
}

bool DecriptImage::isShiftLeft(unsigned char a, unsigned char b, int& n) {
    for (n = 1; n < 8; ++n) {
        if (shiftLeft(a, n) == b)
            this->addOperation("Shift Left", n);
            return true;
    }
    return false;
}

void DecriptImage::addOperation(const QString& type, int bits) {
    Operation* newOperation = new Operation;
    newOperation->type = type;
    newOperation->bits = bits;
    newOperation->next = head;
    head = newOperation;
}

void DecriptImage::printOperations() const {
    Operation* current = head;
    while (current != nullptr) {
        string operationType = current->type.toStdString();
        cout << "----------------------------------------------" << std::endl;
        cout << "Operation: " << operationType << ", Bits: " << current->bits << std::endl;
        cout << "----------------------------------------------" << std::endl;
        current = current->next;
    }
}

bool DecriptImage::Run() {
    int width = 0, height = 0;
    int maskWidth = 0, maskHeight = 0;

    // Cargar máscara (imagen)
    unsigned char* pixelDataMask = loadPixels(maskImage, maskWidth, maskHeight);

    // Cargar imagen transformada final
    unsigned char* pixelDataId = loadPixels(idImage, width, height);

    for (int i = steps; i >= 0; --i) {
        // Construir ruta del archivo de enmascaramiento
        QString maskFile = base_path + QString("M%1.txt").arg(i);

        if (!pixelDataMask) {
            cout << "No se pudo cargar la imagen de máscara." << std::endl;
            return false;
        }

        // Cargar datos desde el archivo de enmascaramiento (resultado)
        unsigned int* maskingData = loadSeedMasking(
            maskFile.toUtf8().constData(), seed, n_pixeles);

        if (!maskingData) {
            cout << "No se pudo cargar el archivo de enmascaramiento: " << maskFile.toStdString() << std::endl;
            return false;
        }

        // Revertir operación de enmascaramiento
        unsigned char* pixelBefore = loadPixelsBeforeStep(maskingData, pixelDataMask, n_pixeles);

        // Detectar operación usada entre pixelBefore y pixelDataId
        // Supongamos que se usa el primer byte como muestra
        unsigned char original = pixelBefore[0];
        unsigned char transformado = pixelDataId[0];
        unsigned char x;
        int param;

        if (this->isXOR(original, transformado, x)) {
            std::cerr << "Se detectó XOR con clave: " << (int)x << std::endl;
        } else if (this->isRotationRight(original, transformado, param)) {
            std::cerr << "Se detectó Rotación Derecha con " << param << " bits" << std::endl;
        } else if (this->isRotationLeft(original, transformado, param)) {
            std::cerr << "Se detectó Rotación Izquierda con " << param << " bits" << std::endl;
        } else if (this->isShiftRight(original, transformado, param)) {
            std::cerr << "Se detectó Desplazamiento Derecha con " << param << " bits" << std::endl;
        } else if (this->isShiftLeft(original, transformado, param)) {
            std::cerr << "Se detectó Desplazamiento Izquierda con " << param << " bits" << std::endl;
        } else {
            std::cerr << "No se detectó ninguna operación válida entre píxeles." << std::endl;
            return false;
        }

        // Actualizar la imagen a la anterior (para el siguiente paso)
        pixelDataId = pixelBefore;
        n_pixeles = 0;
    }

    // Mostrar operaciones detectadas (en orden inverso)
    // printOperations();

    delete[] pixelDataMask;
    delete[] pixelDataId;
    return true;
}
