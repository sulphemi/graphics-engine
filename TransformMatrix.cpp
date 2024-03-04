#include "TransformMatrix.h"

/* im sure there's prettier ways of doing this, yet too, uglier ways */
TransformMatrix::TransformMatrix(
        double a, double b, double c, double d,
        double e, double f, double g, double h,
        double i, double j, double k, double l,
        double m, double n, double o, double p ) {
    add_column(a, e, i, m);
    add_column(b, f, j, n);
    add_column(c, g, k, o);
    add_column(d, h, l, p);
}

TransformMatrix TransformMatrix::translation(double x, double y, double z) {
    return TransformMatrix(
        1, 0, 0, x,
        0, 1, 0, y,
        0, 0, 1, z,
        0, 0, 0, 1
    );
}

TransformMatrix TransformMatrix::scale(double x, double y, double z) {
    return TransformMatrix(
        x, 0, 0, 0,
        0, y, 0, 0,
        0, 0, z, 0,
        0, 0, 0, 1
    );
}

TransformMatrix TransformMatrix::rotX(double theta) {
    return TransformMatrix(
        1, 0              , 0         , 0,
        0, cos(theta)     , sin(theta), 0,
        0, -1 * sin(theta), cos(theta), 0,
        0, 0              , 0         , 1
    );
}

TransformMatrix TransformMatrix::rotY(double theta) {
    return TransformMatrix(
        cos(theta), 0, -1 * sin(theta), 0,
        0         , 1, 0              , 0,
        sin(theta), 0, cos(theta)     , 0,
        0         , 0, 0              , 1
    );
}

TransformMatrix TransformMatrix::rotZ(double theta) {
    return TransformMatrix(
        cos(theta)     , sin(theta), 0, 0,
        -1 * sin(theta), cos(theta), 0, 0,
        0              , 0         , 1, 0,
        0              , 0         , 0, 1
    );
}