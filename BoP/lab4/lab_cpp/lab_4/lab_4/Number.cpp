#include "Number.h"
#include "Header.h"

Number::Number(void) {
	this-> numByDigit = getNumVector(0);
}

Number::Number(int num) {
	this->numByDigit = getNumVector(num);
}

Number::Number(vector<int> v) {
	for (int i = 0; i < v.size(); i++)
	{
		this->numByDigit.push_back(v[i]);
	}	
}

Number::Number(const Number& obj) {
	this->numByDigit = obj.numByDigit;
}

vector<int> Number::getNumVector(int number) {

	vector<int> numByDigit;
	int num_copy = number;

	for (int i = pow(10, trunc(log10(num_copy))); i > 0; i /= 10)
	{
		numByDigit.push_back(num_copy / i);
		num_copy -= (num_copy / i) * i;
	}
	return numByDigit;
}

void Number::setNum(int number) {
	this->numByDigit = getNumVector(number);
}

void Number::outputDigits() {
	for (int i = 0; i < this->numByDigit.size(); i++)
	{
		cout << "10 ^ " << this->numByDigit.size() - i - 1 << ": " << this->numByDigit[i] << endl;
	}
	cout << "Full number: " << to_string(vectorToNum(*this)) << endl << endl;
}

Number Number::operator++()
{
	for (int i = 0; i < numByDigit.size(); i++)
	{
		numByDigit[i]++;
	}

	return *this;
}

Number Number::operator--()
{
	for (int i = 0; i < numByDigit.size(); i++)
	{
		numByDigit[i]--;
	}

	return *this;
}

Number Number::operator+(Number &obj) {

	int diff = this->numByDigit.size() - obj.numByDigit.size();

	for (int i = obj.numByDigit.size() - 1; i >= 0; i--)
	{
		numByDigit[i + diff] += obj.numByDigit[i];
		if (numByDigit[i + diff] >= 10) {
			numByDigit[i + diff - 1] += 1;
			numByDigit[i + diff] = numByDigit[i + diff] - 10;
		}
	}

	return *this;
}

Number Number::operator>(Number& obj) {

	int a = vectorToNum((*this)), b = vectorToNum(obj);
	this->numByDigit =  a > b ? getNumVector(a) : getNumVector(b);

	return *this;
}