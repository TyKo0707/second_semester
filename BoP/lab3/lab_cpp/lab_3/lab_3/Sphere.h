#pragma once
#include <iostream>
using namespace std;

class Sphere {
	int x, y, z, rad;
public:
	void setdata(int xx, int yy, int zz, int radius) {
		x = xx; y = yy; z = zz; rad = radius;
	}
	int pointsp(int a, int b, int c);
	void printsp() {
		cout << endl << "Sphere center is: (" << x << ";" << y << ";" << z << ") \nRadius: " << rad;
	}
};
