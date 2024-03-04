#ifndef T_MATRIX_H
#define T_MATRIX_H

#include "Matrix.h"
#include <cmath>

class TransformMatrix : public Matrix {
    public:
    TransformMatrix(
        double a, double b, double c, double d,
        double e, double f, double g, double h,
        double i, double j, double k, double l,
        double m, double n, double o, double p
        );

    static TransformMatrix translation(double x, double y, double z);
    static TransformMatrix scale(double x, double y, double z);
    static TransformMatrix rotX(double theta);
    static TransformMatrix rotY(double theta);
    static TransformMatrix rotZ(double theta);
};

#endif // T_MATRIX_H