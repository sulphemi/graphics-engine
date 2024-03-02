#include <bits/stdc++.h>
using namespace std;

class Screen {
private:
    int **img;
    int height;
    int width;

    /* Checks if point is valid */
    inline bool in_bounds(int x, int y) {
        return (x >= 0) && (x < width) && (y >= 0) && (y < height);
    }

    /* Converts three integral rgb values to the color's 32 bit integer representation */
    inline int rgb(int r, int g, int b) {
        return (r << 16) | (g << 8) | (b << 0);
    }

    inline int r(int c) {
        return (c >> 16) & 0xFF;
    }

    inline int g(int c) {
        return (c >> 8) & 0xFF;
    }

    inline int b(int c) {
        return (c >> 0) & 0xFF;
    }

public:
    Screen(int width, int height) {
        this->width = width;
        this->height = height;
        img = new int*[height];
        for (int i = 0; i < height; ++i) {
            img[i] = new int[width]();
        }
    }

    ~Screen() {
        for (int i = 0; i < width; ++i) {
            delete[] img[i];
        }
        delete[] img;
    }

    bool plot(int x, int y, int c) {
        if (in_bounds(x, y)) {
            img[y][x] = c;
            return true;
        } else {
            return false;
        }
    }

    bool plot(int x, int y, int r, int g, int b) {
        return plot(x, y, rgb(r, g, b));
    }

    void write_to_ppm(string file) {
        ofstream to_file(file);
        if (! to_file.is_open()) {
            cerr << "error opening file! " << file << endl;
            return;
        }

        // header
        to_file << "P3" << '\n';
        to_file << width << " " << height << '\n';
        to_file << "255" << '\n';

        // contents
        for (int i = 0; i < height; ++i) {
            for (int k = 0; k < width; ++k){
                to_file << r(img[i][k]) << ' ';
                to_file << g(img[i][k]) << ' ';
                to_file << b(img[i][k]) << ' ';
            }
            to_file << '\n';
        }

        to_file.close();
    }
};

int main() {
    Screen a(2, 3);
    cout << a.plot(0, 0, 1, 0, 0) << endl;
    cout << a.plot(0, 1, 1, 0, 1) << endl;
    cout << a.plot(1, 1, 1, 1, 1) << endl;
    cout << a.plot(1, 2, 1, 1, 2) << endl;
    a.write_to_ppm("aaa.ppm");
}