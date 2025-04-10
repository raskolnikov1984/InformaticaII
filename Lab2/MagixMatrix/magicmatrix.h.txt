#ifndef MAGICMATRIX_H
#define MAGICMATRIX_H

class MagicMatrix
{
public:
    int** Matrix;
    int dimension;

    MagicMatrix(int dimension);
    ~MagicMatrix();

    int** create_matrix(int dimension);
    void fillMatrix();
    bool is_magic_matrix();
    void print_matrix();
};

#endif // MAGICMATRIX_H
