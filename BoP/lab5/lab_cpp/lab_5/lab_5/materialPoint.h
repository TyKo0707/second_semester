#pragma once
#include <stdlib.h> 
#include <stdio.h>
#include <time.h> 
#include <iostream>
#include <vector>
#include <math.h> // cos, sin
using namespace std;

class materialPoint {
protected:	
	int a1 = rand() % 5 + 1, a2 = rand() % 5 + 1, x0 = rand() % 5 + 1, y0 = rand() % 5 + 1;
	double x, y, t;
	virtual double findX() = 0;
	virtual double findY() = 0;
	virtual double getDistance(materialPoint* mp) = 0;
	materialPoint(double t);
public:
	virtual double getX() = 0;
	virtual double getY() = 0;
	virtual void getCoordinates() = 0;
};

class materialPointX : public materialPoint {
private:
	double findX() override;
	double findY() override;
	double x = findX(), y = findY();
public:
	double getX() override {
		return x;
	}
	double getY() override {
		return y;
	}
	void getCoordinates() override {
		cout << "(x;y) = " << x << "; " << y << endl;
	}
	double getDistance(materialPoint* mp) override;
	materialPointX(float t) : materialPoint(t) {};
};

class materialPointXY : public materialPoint {
private:
	double findX() override;
	double findY() override;
	double x = findX(), y = findY();
public:
	double getX() override {
		return x;
	}
	double getY() override {
		return y;
	}
	void getCoordinates() override {
		cout << "(x;y) = " << x << "; " << y << endl;
	}
	double getDistance(materialPoint* mp) override;
	materialPointXY(float t) : materialPoint(t) {};
};