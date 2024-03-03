#include "Screen.cpp"

int main() {
    Screen a(2, 3);
    cout << a.plot(0, 0, 1, 0, 0) << endl;
    cout << a.plot(0, 1, 1, 0, 1) << endl;
    cout << a.plot(1, 1, 1, 1, 1) << endl;
    cout << a.plot(1, 2, 1, 1, 2) << endl;
    a.write_to_ppm("aaa.ppm");
}