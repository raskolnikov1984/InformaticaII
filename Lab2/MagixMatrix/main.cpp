#include <gtest/gtest.h>
#include <iostream>
#include "magicmatrix.h"

using namespace std;

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    int size;
    cout << "Ingrese el tamaño de la matriz (n para una matriz nxn): ";
    cin >> size;

    if (size < 2) {
        cout << "La matriz debe ser al menos de tamaño 2x2." << endl;
        return 1;
    }

    MagicMatrix matrix(size);
    matrix.fillMatrix();
    matrix.print_matrix();

    if (matrix.is_magic_matrix()) {
        cout << "It is a magic matrix" << endl;
    } else {
        cout << "¡It is not a magic matrix!" << endl;
    }
    return 0;
}
