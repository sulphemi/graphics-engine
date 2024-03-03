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

    /* returns a new 4x4 identity matrix */
    static Matrix identity() {
        Matrix id;
        id.add_column(1, 0, 0, 0);
        id.add_column(0, 1, 0, 0);
        id.add_column(0, 0, 1, 0);
        id.add_column(0, 0, 0, 1);
        return id;
    }

    void add_column(double a, double b, double c, double d) {
        column col = {a, b, c, d};
        m.push_back(col);
    }

    inline void add_point(double x, double y, double z) { add_column(x, y, z, 1); }

    /* multiply other by this matrix and set this matrix to result */
    /* ie. "this = other * this" (note ordering) */
    /* only accepts 4x4 arrays for other */
    /* but should in theory work for all valid matrix multiplications */
    void multiply(Matrix other) {
        for (int i = 0; i < m.size(); ++i) {
            column new_col;
            for (int r = 0; r < COL_SIZE; ++r) {
                double new_val = 0;
                for (int c = 0; c < COL_SIZE; ++c) {
                    new_val += other.m[c][r] * m[i][r];
                }
                new_col[r] = new_val;
            }
            m[i] = new_col;
        }
    }

    /* return matrix as a string, mainly for debugging */
    /* only accepts Nx4 matrices*/
    string to_string() {
        stringstream s1, s2, s3, s4;
        for (column col : m) {
            s1 << col[0] << " ";
            s2 << col[1] << " ";
            s3 << col[2] << " ";
            s4 << col[3] << " ";
        }
        return s1.str() + "\n" + s2.str() + "\n" + s3.str() + "\n" + s4.str();
    }
};