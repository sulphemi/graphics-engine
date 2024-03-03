#include "Screen.cpp"

inline int rgb(int r, int g, int b) { return (r << 16) | (g << 8) | (b << 0); }
int main() {
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