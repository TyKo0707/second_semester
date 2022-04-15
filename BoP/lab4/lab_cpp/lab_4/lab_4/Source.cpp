#include "Header.h"
#include "Number.h"

int vectorToNum(Number& num) {
	int n = 0;
	for (int i = 0; i < num.numByDigit.size(); i++)
	{
		n += num.numByDigit[i] * pow(10, num.numByDigit.size() - i - 1);
	}
	return n;
}