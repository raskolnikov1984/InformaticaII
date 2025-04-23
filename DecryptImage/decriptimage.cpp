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
    operations=0;

    pixelDataId = loadPixels(idImage, widthId, heigthId);
    pixelDataGeneralMask = loadPixels(generalMask, widthGm, heigthGm);
    pixelDataMask = loadPixels(maskImage, widthM, heigthM);
    head=new Operation[steps+1];
}

DecriptImage::~DecriptImage() {
    delete[] pixelDataId;
    delete[] pixelDataGeneralMask;
    delete[] pixelDataMask;
}

unsigned char* DecriptImage::loadPixelsBeforeStep(unsigned int* pixelSeedMasking, unsigned char* pixelDataMask, int dataSize){
    unsigned char* pixelData = new unsigned char[dataSize];

    for(int i=0; i < dataSize; i++){
        pixelData[i] = (pixelSeedMasking[i] - pixelDataMask[i] + 256) % 256;
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
        if (shiftRight(img[i], bits) != imgId[i])
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
    Operation newOperation;
    newOperation.type = type;
    newOperation.bits = bits;
    newOperation.next = head;
    newOperation.maskFile = this->maskFile.remove(
        this->base_path);
    head[operations] = newOperation;
    operations++;
}



bool DecriptImage::detectTransform(
    unsigned char* pixelBefore, unsigned char* pixelDataGeneralMaskRegion,
    unsigned char* pixelDataIdRegion, int& seed, int& n_pixels){

    bool operation_found = false;
    unsigned char* result = new unsigned char[n_pixels];
    Img1XORImg2(pixelBefore, pixelDataGeneralMaskRegion, result, n_pixels);

    if(this->isXOR(result, pixelDataGeneralMaskRegion, pixelDataIdRegion , seed, n_pixels)){
        qDebug()  << "XOR";
        return true;
    }

    for(int bits=1; bits < 8; bits++){
        operation_found = this->isShiftLeft(pixelBefore, pixelDataIdRegion, n_pixels, bits);

        if(operation_found){
            qDebug()  << "Shift Left";
            return true;
        }

        operation_found = this->isShiftRight(pixelBefore, pixelDataIdRegion, n_pixels, bits);

        if(operation_found){
            qDebug()  << "Shift Right";
            return true;
        }

        operation_found = this->isRotationRight(pixelBefore, pixelDataIdRegion, n_pixels, bits);

        if(operation_found){
            qDebug()  << "Rotation Right";
            return true;
        }

        operation_found = this->isRotationLeft(pixelBefore, pixelDataIdRegion, n_pixels, bits);

        if(operation_found){
            qDebug()  << "Rotation Left";
            return true;
        }
    }

    return false;
}

void DecriptImage::printOperations() const {
    Operation current;
    for(int i=0; i<operations; i++){
        current = head[i];
        string operationType = current.type.toStdString();
        cout << "----------------------------------------------" << endl;
        cout << "Operation: " << operationType << ", Bits: " << current.bits << endl;
        cout << "----------------------------------------------" << endl;
    }
}

unsigned char* DecriptImage::copyRegion(unsigned char* pixelData, int start, int end,int width, int height) {
    // Verificar que los parámetros sean válidos
    int pixels = width * height * 3;

    if (!pixelData || start < 0 || end <= start || end > pixels) {
        std::cerr << "Parámetros inválidos para que la region sea copiada." << std::endl;
        qDebug() << "Start" << start;
        qDebug() << "End" << end;
        qDebug() << "Pixeles" << pixels;
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

unsigned char* DecriptImage::decriptIdImage(unsigned char* pixelDataIdRegion, unsigned char* pixelDataGeneralMaskRegion, int& width, int& heigth){
    Operation current;
    OperationTypes operation;

    for(int i=0; i < operations; i++) {
        current = head[i];
        if(current.type == "XOR"){
            operation = OperationTypes::XOR;
        } else if(current.type == "RotationRight"){
            operation = OperationTypes::RotationRight;
        } else if(current.type == "RotationLeft"){
            operation = OperationTypes::RotationLeft;
        } else if(current.type == "ShiftRight"){
            operation = OperationTypes::ShiftRight;
        } else {
            operation = OperationTypes::ShiftLeft;
        };
        pixelDataIdRegion = decriptRegion(pixelDataIdRegion, pixelDataGeneralMaskRegion, operation, n_pixeles, widthM, heigthM, seed, current.bits);
    }

    return pixelDataIdRegion;
}

unsigned char* DecriptImage::decriptRegion(unsigned char* pixelData, unsigned char* pixelDataGeneralMaskRegion, OperationTypes operationType, int& dataSize, int width, int height, int& seed, int& bits){
    unsigned char* region = new unsigned char[dataSize];
    int end = seed+dataSize;
    unsigned char* PixelDataIdRegion = copyRegion(
        pixelDataId, seed, end, widthId, heigthId);

    switch(operationType){
    case 1:
        Img1XORImg2(pixelData, pixelDataGeneralMaskRegion, region, dataSize);
        break;
    case 2:
        for(int i=0; i< dataSize;i++){
            region[i] = rotateLeft(PixelDataIdRegion[i], bits);
        }
        break;
    case 3:
        for(int i=0; i< dataSize;i++){
            region[i] = rotateRight(PixelDataIdRegion[i], bits);
        }
        break;
    case 4:
        for(int i=0; i< dataSize;i++){
            region[i] = shiftLeft(PixelDataIdRegion[i], bits);
        }
        break;
    case 5:
        for(int i=0; i< dataSize;i++){
            region[i] = shiftRight(PixelDataIdRegion[i], bits);
        }
        break;
    }

    return region;
}

bool DecriptImage::Run() {
    bool operation_found=false;
    unsigned char* pixelDataIdRegion = nullptr;
    unsigned char* pixelDataGeneralMaskRegion = nullptr;

    int start = 0;
    int end = 0;

    for (int i = steps; i >= 0; --i) {
        // Construir ruta del archivo de enmascaramiento
        this->maskFile = base_path + QString("M%1.txt").arg(i);
        cout << "----------------------------------------------" << std::endl;
        qDebug() << "Aplicando operaciones para" << QString("M%1.txt").arg(i);
        cout << "----------------------------------------------" << std::endl;

        if (!pixelDataMask) {
            cout << "No se pudo cargar la imagen de máscara." << endl;
            return false;
        }

        // Cargar datos desde el archivo de enmascaramiento (resultado)
        n_pixeles = 0;
        unsigned int* maskingData = loadSeedMasking(maskFile.toUtf8().constData(), seed, n_pixeles);

        if (!maskingData) {
            cout << "No se pudo cargar el archivo de enmascaramiento: " << maskFile.toStdString() << endl;
            return false;
        }

        // Mostrar información de control en consola
        cout << "Semilla: " << seed << endl;
        cout << "Cantidad de píxeles leídos: " << n_pixeles << endl;

        n_pixeles *= 3;
        // Revertir operación de enmascaramiento
        unsigned char* pixelBefore = loadPixelsBeforeStep(maskingData, pixelDataMask, n_pixeles);

        if (!pixelBefore) {
            cout << "Error al cargar los datos de píxeles antes del paso." << endl;
            delete[] pixelDataIdRegion;
            delete[] pixelDataGeneralMaskRegion;
            delete[] maskingData;
            delete[] pixelBefore;
            return false;
        }

        start = seed;
        end = seed+(n_pixeles);

        pixelDataGeneralMaskRegion = copyRegion(pixelDataGeneralMask, start, end, widthGm, heigthGm);
        if (!pixelDataGeneralMaskRegion) {
            cout << "Error al Copiar los pixels de I_M" << endl;
            delete[] pixelDataIdRegion;
            delete[] pixelDataGeneralMaskRegion;
            delete[] maskingData;
            delete[] pixelBefore;
            return false;
        }

        pixelDataIdRegion = copyRegion(pixelDataId, start, end, widthId, heigthId);
        if (!pixelDataIdRegion) {
            cout << "Error al Copiar los pixels de I_D" << endl;
            delete[] pixelDataIdRegion;
            delete[] pixelDataGeneralMaskRegion;
            delete[] maskingData;
            delete[] pixelBefore;
            return false;
        }

        if(head){
            pixelDataIdRegion = decriptIdImage(pixelDataIdRegion, pixelDataGeneralMaskRegion, widthM, heigthM);
        }

        operation_found = this->detectTransform(pixelBefore, pixelDataGeneralMaskRegion, pixelDataIdRegion, seed, n_pixeles);


        // Detectar operación usada entre pixelBefore y pixelDataIdRegion
        qDebug() << "Operacion Encontrada" << operation_found;


        if(!operation_found){
            cerr<<"Ninguna operación detectada en paso "<<i<<endl;
            delete[] maskingData;
            delete[] pixelBefore;
            delete[] pixelDataMask;
            delete[] pixelDataId;
            delete[] pixelDataGeneralMask;
            delete[] pixelDataIdRegion;
            delete[] pixelDataGeneralMaskRegion;
            printOperations();
            return false;

        n_pixeles = 0;
        start = 0;
        end = 0;

        delete[] maskingData;
        maskingData = nullptr;

        delete[] pixelDataIdRegion;
        pixelDataIdRegion = nullptr;

        delete[] pixelDataGeneralMaskRegion;
        pixelDataGeneralMaskRegion = nullptr;
        }
    }

    // Mostrar operaciones detectadas (en orden inverso)
    printOperations();

    delete[] pixelDataMask;
    delete[] pixelDataId;
    delete[] pixelDataGeneralMask;
    delete[] pixelDataIdRegion;
    delete[] pixelDataGeneralMaskRegion;
    return true;
}
