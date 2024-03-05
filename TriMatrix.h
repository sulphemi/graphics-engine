#ifndef TRI_MATRIX_H
#define TRI_MATRIX_H

#include "Matrix.h"
#include "Screen.h"

class TriMatrix : private Matrix {
    /* a matrix that only holds triplets of values representing the vertices of a triangle */
    public:
    using Matrix::multiply;
    using Matrix::to_string;

    void add_tri(
        double a, double b, double c,
        double d, double e, double f,
        double g, double h, double i
    );

    void draw_edges(Screen& s, int color);
};

#endif // TRI_MATRIX_H