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
    generalMask = base_path + "I_M.bmp";
    int seed = 0;
    int n_pixeles = 0;
}

DecriptImage::~DecriptImage() {
}

unsigned char* DecriptImage::loadPixelsBeforeStep(unsigned int* pixelSeedMasking, unsigned char* pixelDataMask, int dataSize){
    unsigned char* pixelData = new unsigned char[dataSize];

    for(int i=0; i < dataSize; i++){
        pixelData[i] = pixelSeedMasking[i] - pixelDataMask[i];
    }

    return pixelData;
}


bool DecriptImage::isXOR(unsigned char* imgXOR, unsigned char* generalMask, unsigned char* imgId, int &seed, int &n_pixels) {
    unsigned char* reverseXOR = new unsigned char[n_pixels * 3];
    Img1XORImg2(imgXOR, generalMask, reverseXOR, n_pixels * 3);
    for(int i=0; i < n_pixels; i++){
        if(reverseXOR[i] == imgId[i+seed]){
            continue;
        }
        return false;
    }
    this->addOperation("XOR", 0);
    return true;
}

bool DecriptImage::isRotationLeft(unsigned char* img, unsigned char* imgId, int& n_pixels, int& bits) {
    for(int i=0; i < n_pixels; i++){
        if (rotateLeft(img[i], bits) != imgId[i]){
            return false;
        }
    }

    this->addOperation("Rotation Left", bits);
    return true;
}

bool DecriptImage::isRotationRight(unsigned char* img, unsigned char* imgId, int& n_pixels, int& bits){
    for(int i=0; i < n_pixels; i++){
        if (rotateRight(img[i], bits) != imgId[i]){
            return false;
        }
    }

    this->addOperation("Rotation Right", bits);
    return true;
}


bool DecriptImage::isShiftRight(unsigned char* img, unsigned char* imgId, int& n_pixels, int& bits) {
    for (int i = 0; i < n_pixels; i++) {
        if (shiftLeft(img[i], bits) != imgId[i])
            return false;
    }

    this->addOperation("Shift Right", bits);
    return true;
}

bool DecriptImage::isShiftLeft(unsigned char* img, unsigned char* imgId, int& n_pixels, int& bits) {
    for (int i = 0; i < n_pixels; i++) {
        if (shiftLeft(img[i], bits) != imgId[i])
            return false;
    }

    this->addOperation("Shift Left", bits);
    return true;
}

void DecriptImage::addOperation(const QString& type, int bits) {
    Operation* newOperation = new Operation;
    newOperation->type = type;
    newOperation->bits = bits;
    newOperation->next = head;
    head = newOperation;
}

bool DecriptImage::detectTransform(
    unsigned char* pixelBefore, unsigned char* pixelDataGeneralMask,
    unsigned char* pixelDataId, int& seed, int& n_pixels){

    unsigned char* result = new unsigned char[300];
    Img1XORImg2(pixelBefore, pixelDataGeneralMask, result, 300);
    if(this->isXOR(result, pixelDataGeneralMask, pixelDataId , seed, n_pixels))
        return true;

    // for(int bits=1; bits < 8; bits++){
    //     if(this->isShiftLeft(pixelBefore, pixelDataId,n_pixels, bits)){
    //         return true;
    //     } else if(this->isShiftRight(pixelBefore, pixelDataId,n_pixels, bits)){
    //         return true;
    //     } else if(this->isRotationRight(pixelBefore, pixelDataId,n_pixels, bits)){
    //         return true;
    //     } else if(this->isRotationLeft(pixelBefore, pixelDataId,n_pixels, bits)){
    //         return true;
    //     } else {
    //         continue;
    //     }
    //}

    delete[] pixelDataGeneralMask;
    delete[] pixelBefore;
    delete[] pixelDataId;

    return false;
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
    int generalMaskWidth = 0, generalMaskHeight = 0;
    int maskWidth = 0, maskHeight = 0;

    // Cargar máscara (imagen)
    unsigned char* pixelDataMask = loadPixels(maskImage, maskWidth, maskHeight);

    // Cargar imagen transformada final
    unsigned char* pixelDataId = loadPixels(idImage, width, height);

    // Cargar imagen transformada final
    unsigned char* pixelDataGeneralMask = loadPixels(generalMask, generalMaskWidth, generalMaskHeight);

    for (int i = steps; i > 0; --i) {
        // Construir ruta del archivo de enmascaramiento
        QString maskFile = base_path + QString("M%1.txt").arg(i);

        if (!pixelDataMask) {
            delete[] pixelDataId;
            cout << "No se pudo cargar la imagen de máscara." << std::endl;
            return false;
        }

        n_pixeles = 0;
        // Cargar datos desde el archivo de enmascaramiento (resultado)
        unsigned int* maskingData = loadSeedMasking(
            maskFile.toUtf8().constData(), seed, n_pixeles);

        if (!maskingData) {
            cout << "No se pudo cargar el archivo de enmascaramiento: " << maskFile.toStdString() << std::endl;
            return false;
        }

        // Revertir operación de enmascaramiento
        unsigned char* pixelBefore = loadPixelsBeforeStep(maskingData, pixelDataMask, n_pixeles*3);

        // Detectar operación usada entre pixelBefore y pixelDataId
        // Supongamos que se usa el primer byte como muestra


        if(~this->detectTransform(pixelBefore, pixelDataGeneralMask, pixelDataId, seed, n_pixeles)){
            return false;
        }

        pixelDataId = pixelBefore;
        n_pixeles = 0;
    }

    // Mostrar operaciones detectadas (en orden inverso)
    printOperations();
    return true;
}
