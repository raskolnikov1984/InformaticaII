#include "magicmatrix.h"
#include <iostream>

using namespace std;

MagicMatrix::MagicMatrix(int dimension) : dimension(3){
    Matrix = create_matrix(dimension);
}

int** MagicMatrix::create_matrix(int dimension){
    int** matrix = new int*[dimension];
    for (int i = 0; i < dimension; ++i) {
        matrix[i] = new int[dimension];
        for (int j = 0; j < dimension; ++j) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

MagicMatrix::~MagicMatrix(){
    for (int i = 0; i < dimension; ++i) {
        delete[] Matrix[i];
    }
    delete[] Matrix;
}

void MagicMatrix::fillMatrix() {
    cout << "Type the elements for Matrix (" << dimension * dimension << " numbers):" << endl;
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            cout << "Type element: " << "[" << i << "]" << "[" << j << "]";
            cin >> Matrix[i][j];
            cout << endl;
        }
    }
}
void MagicMatrix::print_matrix(){
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            cout << this->Matrix[i][j]<< " ";
        }
        cout << std::endl;
    }
}

bool MagicMatrix::is_magic_matrix() {
    int sumDiag1 = 0, sumDiag2 = 0;
    for (int i = 0; i < dimension; ++i) {
        sumDiag1 += Matrix[i][i];
        sumDiag2 += Matrix[i][dimension - i - 1];
    }

    if (sumDiag1 != sumDiag2) return false;

    for (int i = 0; i < dimension; ++i) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < dimension; ++j) {
            rowSum += Matrix[i][j];
            colSum += Matrix[j][i];
        }
        if (rowSum != sumDiag1 || colSum != sumDiag1) return false;
    }

    return true;
}
