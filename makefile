test:
	make all
	# g++ -std=c++17 -I/home/sap/CP/headers/ -o test.out test.cpp
	g++ -c test.cpp
	g++ -o test.out Screen.o Matrix.o EdgeMatrix.o TransformMatrix.o TriMatrix.o test.o
	./test.out
	# xdg-open aaa.ppm > /dev/null 2>&1
	convert *.ppm out.gif && xdg-open out.gif > /dev/null 2>&1
all: Screen.o Matrix.o EdgeMatrix.o TransformMatrix.o TriMatrix.o
Screen.o: Screen.cpp
	g++ -c Screen.cpp
Matrix.o: Matrix.cpp
	g++ -c Matrix.cpp
EdgeMatrix.o: EdgeMatrix.cpp
	g++ -c EdgeMatrix.cpp
TransformMatrix.o: TransformMatrix.cpp
	g++ -c TransformMatrix.cpp
TriMatrix.o: TriMatrix.cpp
	g++ -c TriMatrix.cpp