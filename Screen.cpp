#include <bits/stdc++.h>
using namespace std;

class Screen {
private:
    /* the underlying array of pixel values. */
    /* note that the x-axis extends left->right */
    /* and the y-axis extends top->down */
    /* img[y][x] to access the pixel at (x, y) */
    int **img;
    int height;
    int width;

    /* checks if point is valid (within bounds of img) */
    inline bool in_bounds(int x, int y) {
        return (x >= 0) && (x < width) && (y >= 0) && (y < height);
    }

    /* converts three integral rgb values to the color's 32 bit integer representation */
    inline int rgb(int r, int g, int b) { return (r << 16) | (g << 8) | (b << 0); }

    /* vice versa */
    inline int r(int c) { return (c >> 16) & 0xFF; }
    inline int g(int c) { return (c >> 8) & 0xFF; }
    inline int b(int c) { return (c >> 0) & 0xFF; }

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

    /* changes the color of the pixel at (x, y) to color c */
    bool plot(int x, int y, int c) {
        if (in_bounds(x, y)) {
            img[y][x] = c;
            return true;
        } else {
            return false;
        }
    }

    /* ditto but for three rgb values */
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