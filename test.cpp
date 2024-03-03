#include "Screen.cpp"

inline int rgb(int r, int g, int b) { return (r << 16) | (g << 8) | (b << 0); }
int main() {
    Screen a(50, 50);
    a.vertical_line(25, 0, 50, rgb(100, 100, 0));
    a.horizontal_line(0, 50, 25, rgb(0, 100, 100));
    a.write_to_ppm("aaa.ppm");
}