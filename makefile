test:
	g++ -std=c++17 -I/home/sap/CP/headers/ -o test.out test.cpp
	./test.out
	xdg-open aaa.ppm > /dev/null 2>&1