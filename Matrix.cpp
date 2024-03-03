#include <bits/stdc++.h>
using namespace std;
constexpr int COL_SIZE = 4; // for our purposes we will probably only deal with matrices of height 4
using column = array<double, COL_SIZE>;

class Matrix {
public:
    /* the matrix is stored in column-major order, */
    /* expandable to the right for more columns */
    vector<column> m; // feeling cute, might private later

    Matrix() {

    }

    void add_point(double a, double b, double c, double d) {
        column col = {a, b, c, d};
        m.push_back(col);
    }

    inline void add_point(double x, double y, double z) { add_point(x, y, z, 1); }
};