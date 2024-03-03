#include "Screen.cpp"
#include "Matrix.cpp"

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
    Matrix mat1;
    mat1.add_column(1, 2, 3, 4);
    mat1.add_column(5, 6, 7, 8);
    mat1.add_column(9, 10, 11, 12);
    mat1.add_column(13, 14, 15, 16);

    Matrix mat2;
    mat2.add_column(1, 0, 0, 0);
    mat2.add_column(0, 2, 0, 0);
    mat2.add_column(0, 0, 3, 0);
    mat2.add_column(0, 0, 7, 4);

    cout << "Original Matrix:" << endl;
    for (const auto& col : mat1.m) {
        for (const auto& val : col) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;

    mat1.multiply(mat2);

    cout << "Multiplied Matrix:" << endl;
    for (const auto& col : mat1.m) {
        for (const auto& val : col) {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << "to string:" << endl;
    cout << mat1.to_string() << endl;

    return 0;
}
