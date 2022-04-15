#pragma once
#include <iostream>
using namespace std;

class Sphere {
	int x, y, z, rad;
public:
	Sphere(int x, int y, int z, int rad);
	int pointsp(int a, int b, int c);
	void printsp(int n) {
		cout << endl << "Center of sphere with number " << n <<" is: (" << x << "; " << y << "; " << z << ") \nRadius : " << rad;
	}
};
