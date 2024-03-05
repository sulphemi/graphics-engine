#include "TriMatrix.h"
using namespace std;

void TriMatrix::add_tri(
    double a, double b, double c,
    double d, double e, double f,
    double g, double h, double i
) {
    add_point(a, b, c);
    add_point(d, e, f);
    add_point(g, h, i);
}

void TriMatrix::draw_edges(Screen &s, int color) {
    for (int i = 0; i < m.size(); i += 3) {
        column a = m[i];
        column b = m[i + 1];
        column c = m[i + 2];
        s.line(a[0], a[1], b[0], b[1], color);
        s.line(a[0], a[1], c[0], c[1], color);
        s.line(b[0], b[1], c[0], c[1], color);
    }
}