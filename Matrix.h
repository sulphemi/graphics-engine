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
    std::vector<column> m;

    Matrix();

    static Matrix identity();
    void add_column(double a, double b, double c, double d);
    inline void add_point(double x, double y, double z);
    void multiply(Matrix other);
    std::string to_string();
};

#endif // MATRIX_H

