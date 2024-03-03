#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

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
    inline bool in_bounds(int x, int y);

    /* converts three integral rgb values to the color's 32 bit integer representation */
    static inline int rgb(int r, int g, int b);

    /* vice versa */
    static inline int r(int c);
    static inline int g(int c);
    static inline int b(int c);

public:
    /* creates an instance of screen with size width, height */
    Screen(int width, int height);
    ~Screen();

    /* changes the color of the pixel at (x, y) to color c */
    /* returns true if successful (ie x, y are valid), false if not */
    bool plot(int x, int y, int c);

    /* ditto but for three rgb values */
    bool plot(int x, int y, int r, int g, int b);

    /* writes current image contents to ppm file */
    void write_to_ppm(std::string file);

    /* draws a line from (x1, y) to (x2, y) */
    /* accepts all coordinates even if they are not inbounds */
    void horizontal_line(int x1, int x2, int y, int c);

    /* draws a line from (x, y1) to (x, y2) */
    /* accepts all coordinates even if they are not inbounds */
    void vertical_line(int x, int y1, int y2, int c);

    /* draws a line from (x1, y1) to (x2, y2) */
    /* accepts all coordinates even if they are not inbounds */
    void line(int x1, int y1, int x2, int y2, int c);
};

#endif // SCREEN_H

