#ifndef EDGE_MATRIX_H
#define EDGE_MATRIX_H

#include "Matrix.h"
#include "Screen.h"

class EdgeMatrix : private Matrix {
    /* a derivative that only allows points to be added in pairs, ie an edge */ 
    public:
    using Matrix::multiply;

    void add_edge(int x1, int y1, int z1, int x2, int y2, int z2);
    
    /* draw all edges to screen */
    void draw_edges(Screen s, int color);
};

#endif // EDGE_MATRIX_H