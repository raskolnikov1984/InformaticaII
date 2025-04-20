#include "decriptimage.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <cstring>
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
    bool equal = true;
    for(int i=0; i < n_pixels; i++){
        if(imgXOR[i] != imgId[i]){
            equal = false;
        }
    }
    if(equal)
        this->addOperation("XOR", 0);
    return equal;
}

bool DecriptImage::isRotationLeft(unsigned char* img, unsigned char* imgId, int& n_pixels, int& bits) {
    bool equal = true;
    for(int i=0; i < n_pixels; i++){
        if (rotateLeft(img[i], bits) != imgId[i]){
            equal = false;
        }
    }

    if(equal)
        this->addOperation("RotationLeft", bits);
    return equal;
}

bool DecriptImage::isRotationRight(unsigned char* img, unsigned char* imgId, int& n_pixels, int& bits){
    for(int i=0; i < n_pixels; i++){
        if (rotateRight(img[i], bits) != imgId[i]){
            return false;
        }
    }

    this->addOperation("RotationRight", bits);
    return true;
}


bool DecriptImage::isShiftRight(unsigned char* img, unsigned char* imgId, int& n_pixels, int& bits) {
    for (int i = 0; i < n_pixels; i++) {
        if (shiftLeft(img[i], bits) != imgId[i])
            return false;
    }

    this->addOperation("ShiftRight", bits);
    return true;
}

bool DecriptImage::isShiftLeft(unsigned char* img, unsigned char* imgId, int& n_pixels, int& bits) {
    for (int i = 0; i < n_pixels; i++) {
        if (shiftLeft(img[i], bits) != imgId[i])
            return false;
    }

    this->addOperation("ShiftLeft", bits);
    return true;
}

void DecriptImage::addOperation(const QString& type, int bits) {
    Operation* newOperation = new Operation;
    newOperation->type = type;
    newOperation->bits = bits;
    newOperation->next = head;
    newOperation->maskFile = this->maskFile.remove(
        this->base_path);
    head = newOperation;
}



bool DecriptImage::detectTransform(
    unsigned char* pixelBefore, unsigned char* pixelDataGeneralMask,
    unsigned char* pixelDataId, int& seed, int& n_pixels){

    bool operation_found = false;
    unsigned char* result = new unsigned char[n_pixels * 3];
    Img1XORImg2(pixelBefore, pixelDataGeneralMask, result, 300);

    if(this->isXOR(result, pixelDataGeneralMask, pixelDataId , seed, n_pixels))
        return true;

    for(int bits=1; bits < 8; bits++){
        operation_found = this->isShiftLeft(pixelBefore, pixelDataId, n_pixels, bits);

        if(operation_found){
            return true;
        }

        operation_found = this->isShiftRight(pixelBefore, pixelDataId, n_pixels, bits);

        if(operation_found){
            return true;
        }

        operation_found = this->isRotationRight(pixelBefore, pixelDataId, n_pixels, bits);

        if(operation_found){
            return true;
        }

        operation_found = this->isRotationLeft(pixelBefore, pixelDataId, n_pixels, bits);

        if(operation_found){
            return true;
        }
    }

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

unsigned char* DecriptImage::copyRegion(unsigned char* pixelData, int start, int end,int width, int height) {
    // Verificar que los parámetros sean válidos
    int pixels = width * height * 3;
    if (!pixelData || start < 0 || end <= start || end > pixels) {
        std::cerr << "Parámetros inválidos." << std::endl;
        return nullptr;
    }

    // Calcular el tamaño de la región a copiar
    int regionSize = end - start;

    // Crear un nuevo puntero para almacenar la copia
    unsigned char* copiedRegion = new unsigned char[regionSize];

    // Copiar la región de píxeles
    memcpy(copiedRegion, pixelData + start, regionSize);

    return copiedRegion;
}

unsigned char* DecriptImage::decriptRegion(unsigned char* pixelData, QString& operationType, int& dataSize){
    unsigned char* region = new unsigned char[dataSize];

    return region;
}

bool DecriptImage::Run() {
    bool operation_found;
    int width = 0, height = 0;
    int generalMaskWidth = 0, generalMaskHeight = 0;
    int maskWidth = 0, maskHeight = 0;

    // Cargar máscara (imagen)
    unsigned char* pixelDataMask = loadPixels(maskImage, maskWidth, maskHeight);

    // Cargar imagen transformada final
    unsigned char* pixelDataId = loadPixels(idImage, width, height);

    unsigned char* pixelDataIdRegion;

    // Cargar imagen transformada final
    unsigned char* pixelDataGeneralMask = loadPixels(generalMask, generalMaskWidth, generalMaskHeight);

    for (int i = steps; i > 0; --i) {
        // Construir ruta del archivo de enmascaramiento
        this->maskFile = base_path + QString("M%1.txt").arg(i);
        cout << "----------------------------------------------" << std::endl;
        qDebug() << "Aplicando operaciones para" << QString("M%1.txt").arg(i);
        cout << "----------------------------------------------" << std::endl;

        if (!pixelDataMask) {
            cout << "No se pudo cargar la imagen de máscara." << endl;
            return false;
        }

        n_pixeles = 0;
        // Cargar datos desde el archivo de enmascaramiento (resultado)
        unsigned int* maskingData = loadSeedMasking(
            maskFile.toUtf8().constData(), seed, n_pixeles);

        if (!maskingData) {
            cout << "No se pudo cargar el archivo de enmascaramiento: " << maskFile.toStdString() << endl;
            return false;
        }

        // Mostrar información de control en consola
        cout << "Semilla: " << seed << endl;
        cout << "Cantidad de píxeles leídos: " << n_pixeles << endl;

        int start = seed;
        int end = seed+(n_pixeles*3);
        pixelDataIdRegion = copyRegion(pixelDataId, start, end, width, height);


        // Revertir operación de enmascaramiento
        unsigned char* pixelBefore = loadPixelsBeforeStep(maskingData, pixelDataMask, n_pixeles);

        if (!pixelBefore) {
            cout << "Error al cargar los datos de píxeles antes del paso." << endl;
            return false;
        }

        // Detectar operación usada entre pixelBefore y pixelDataId
        operation_found = this->detectTransform(pixelBefore, pixelDataGeneralMask, pixelDataIdRegion, seed, n_pixeles);
        qDebug() << "Operacion Encontrada" << operation_found;

        if(!operation_found){
            delete[] pixelBefore;
            return false;
        }

        delete[] pixelDataId;
        pixelDataId = pixelBefore;
    }

    // Mostrar operaciones detectadas (en orden inverso)
    printOperations();
    return true;
}
