#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

class Screen {
private:
    int **img;
    int height;
    int width;

    inline bool in_bounds(int x, int y);
    inline int rgb(int r, int g, int b);
    inline int r(int c);
    inline int g(int c);
    inline int b(int c);

public:
    Screen(int width, int height);
    ~Screen();

    bool plot(int x, int y, int c);
    bool plot(int x, int y, int r, int g, int b);
    void write_to_ppm(std::string file);
    void horizontal_line(int x1, int x2, int y, int c);
    void vertical_line(int x, int y1, int y2, int c);
    void line(int x1, int y1, int x2, int y2, int c);
};

#endif // SCREEN_H

