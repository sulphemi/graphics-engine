#include "EdgeMatrix.h"
using namespace std;

void EdgeMatrix::add_edge(int x1, int y1, int z1, int x2, int y2, int z2) {
    add_point(x1, y1, z1);
    add_point(x2, y2, z2);
}

/* draw all edges to screen */
void EdgeMatrix::draw_edges(Screen& s, int color) {
    for (int i = 0; i < m.size(); i += 2) {
        column a = m[i];
        column b = m[i + 1];
        s.line(a[0], a[1], b[0], b[1], color);
    }
}
