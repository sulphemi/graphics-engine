#include "Screen.h"
using namespace std;


/* checks if point is valid (within bounds of img) */
bool Screen::in_bounds(int x, int y) {
    return (x >= 0) && (x < width) && (y >= 0) && (y < height);
}

/* converts three integral rgb values to the color's 32 bit integer representation */
int Screen::rgb(int r, int g, int b) { return (r << 16) | (g << 8) | (b << 0); }

/* vice versa */
int Screen::r(int c) { return (c >> 16) & 0xFF; }
int Screen::g(int c) { return (c >> 8) & 0xFF; }
int Screen::b(int c) { return (c >> 0) & 0xFF; }

/* creates an instance of screen with size width, height */
Screen::Screen(int width, int height) {
    this->width = width;
    this->height = height;
    img = new int*[height];
    for (int i = 0; i < height; ++i) {
        img[i] = new int[width]();
    }
}

Screen::~Screen() {
    for (int i = 0; i < width; ++i) {
        delete[] img[i];
    }
    delete[] img;
}

/* changes the color of the pixel at (x, y) to color c */
/* returns true if successful (ie x, y are valid), false if not */
bool Screen::plot(int x, int y, int c) {
    if (in_bounds(x, y)) {
        img[y][x] = c;
        return true;
    } else {
        return false;
    }
}

/* ditto but for three rgb values */
bool Screen::plot(int x, int y, int r, int g, int b) {
    return plot(x, y, rgb(r, g, b));
}

/* writes current image contents to ppm file */
void Screen::write_to_ppm(string file) {
    ofstream to_file(file);
    if (! to_file.is_open()) {
        cerr << "error opening file! " << file << endl;
        return;
    }
    /* ppm header */
    to_file << "P3" << '\n';
    to_file << width << " " << height << '\n';
    to_file << "255" << '\n';
    /* contents */
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

/* draws a line from (x1, y) to (x2, y) */
/* accepts all coordinates even if they are not inbounds */
void Screen::horizontal_line(int x1, int x2, int y, int c) {
    if (x1 > x2) swap(x1, x2);
    for (int i = x1; i <= x2; ++i) {
        plot(i, y, c);
    }
}

/* draws a line from (x, y1) to (x, y2) */
/* accepts all coordinates even if they are not inbounds */
void Screen::vertical_line(int x, int y1, int y2, int c) {
    if (y1 > y2) swap(y1, y2);
    for (int i = y1; i <= y2; ++i) {
        plot(x, i, c);
    }
}

/* draws a line from (x1, y1) to (x2, y2) */
/* accepts all coordinates even if they are not inbounds */
void Screen::line(int x1, int y1, int x2, int y2, int c) {
    // handle zero and undefined slope cases
    if (y1 == y2) {
        horizontal_line(x1, x2, y1, c);
        return;
    }

    if (x1 == x2) {
        vertical_line(x1, y1, y2, c);
        return;
    }

    // swap such that the first point is the leftmost point
    if (x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
    }

    int x = x1;
    int y = y1;

    // A / B is the slope, multiply by both 2 to avoid floating point
    int d;
    int A = (y2 - y1) * 2;
    int B = (x2 - x1) * 2;

    if (abs(x2 - x1) >= abs(y2 - y1)) {
        // bottom-heavy/shallow slope
        if (A > 0) {
            // shallow negative slope
            d = A - B / 2;
            while (x < x2) {
                plot(x, y, c);
                if (d > 0) {
                    y += 1;
                    d -= B;
                }
                x++;
                d += A;
            }
            plot(x2, y2, c);
        } else {
            // shallow positive slope
            d = A + B / 2;
            while (x < x2) {
                plot(x, y, c);
                if (d < 0) {
                    y -= 1;
                    d += B;
                }
                x++;
                d += A;
            }
            plot(x2, y2, c);
        }
    } else {
        // top-heavy/steep slope
        if (A > 0) {
            // steep negative slope
            d = A / 2 - B;
            while (y < y2) {
                plot(x, y, c);
                if (d < 0) {
                    x += 1;
                    d += A;
                }
                y++;
                d -= B;
            }
            plot(x2, y2, c);
        } else {
            // steep positive slope
            d = A / 2 + B;
            while (y > y2) {
                plot(x, y, c);
                if (d > 0) {
                    x += 1;
                    d += A;
                }
                y--;
                d += B;
            }
            plot(x2, y2, c);
        }
    }
}
