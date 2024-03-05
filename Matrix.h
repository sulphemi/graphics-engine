#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <array>
#include <sstream>
#include <string>

constexpr int COL_SIZE = 4; // all matrices used in this should be Nx4
using column = std::array<double, COL_SIZE>;

class Matrix {
public:
    /* the matrix is stored in column-major order, */
    /* expandable to the right for more columns */
    std::vector<column> m; // feeling cute, might private later

    /* returns a new 4x4 identity matrix */
    static Matrix identity();

    /* add [a, b, c, d] to the matrix as a column or [x, y, z, 1]*/
    void add_column(double a, double b, double c, double d);
    inline void add_point(double x, double y, double z) { add_column(x, y, z, 1); }

    /* multiply other by this matrix and set this matrix to result */
    /* ie. "this = other * this" (note ordering) */
    /* only accepts 4x4 arrays for other */
    /* but should in theory work for all valid matrix multiplications */
    void multiply(const Matrix& other);

    /* return matrix as a string, mainly for debugging */
    /* only accepts Nx4 matrices*/
    std::string to_string();
};

#endif // MATRIX_H

