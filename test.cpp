// #include <QtWidgets>
#include "Screen.h"
#include "Matrix.h"
#include "EdgeMatrix.h"
#include "TransformMatrix.h"
#include "TriMatrix.h"

using namespace std;

inline int rgb(int r, int g, int b) { return (r << 16) | (g << 8) | (b << 0); }
void screen_test() {
    Screen a(50, 50);

    // axes
    a.vertical_line(25, 0, 50, rgb(100, 100, 100));
    a.horizontal_line(0, 50, 25, rgb(100, 100, 100));

    // diagonals
    a.line(0, 0, 50, 50, rgb(20, 20, 20));
    a.line(0, 50, 50, 0, rgb(20, 20, 20));

    a.line(0, 10, 25, 25, rgb(100, 100, 0)); //yellow
    a.line(25, 25, 10, 0, rgb(80, 80, 0)); //other yellow?
    a.line(40, 0, 25, 25, rgb(80, 0, 0));  //red
    a.line(50, 10, 25, 25, rgb(80, 40, 0)); //orange
    a.line(25, 25, 0, 40, rgb(0, 0, 80));  // blue
    a.line(25, 25, 10, 50, rgb(0, 80, 80)); //cyan
    a.line(25, 25, 50, 40, rgb(40, 120, 40)); //light green
    a.line(25, 25, 40, 50, rgb(0, 80, 0)); // dark green
    a.write_to_ppm("aaa.ppm");
    // looks just like my graphing calculator LOL
}

int main() {
    Screen a(100, 100);
    EdgeMatrix edges;
    TriMatrix polys;
    int ppmct = 0;
    double theta = 3.1415926 / 10;

    polys.add_tri(10, 10, 0, 90, 10, 0, 50, 90, 0);

    Matrix trans = TransformMatrix::translation(-50, -50, 0);
    trans.multiply(TransformMatrix::rotY(theta));
    trans.multiply(TransformMatrix::translation(50, 50, 0));

    for (int i = 0; i < 10; i++) {
        polys.multiply(trans);
        polys.draw_edges(a, rgb(255, 255, 255));
        a.write_to_ppm("tri_test_" + to_string(ppmct++) + ".ppm");
        a.clear();
    }
}
