#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Number {

private:
	vector<int> getNumVector(int);
	vector<int> numByDigit;
	friend int vectorToNum(Number& num);

public: 
	Number();
	Number(string str);
	Number operator+(Number& obj);
	Number operator>(Number& obj);
	void setNum(int number);
	void outputFraction();
	
};
