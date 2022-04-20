#include "Number.h"
#include <iostream>

int main() {

	vector<int> vect{ 2,4,6,9,1 };
	Number a(12345), b(a), c, d(vect);

	cout << "First vector befor ++: " << endl;
	a.outputDigits();

	cout << "Second vector befor --: " << endl;
	b.outputDigits();

	cout << "First vector after ++: " << endl;
	++a;
	a.outputDigits();

	cout << "Second vector after --: " << endl;
	--b;
	b.outputDigits();

	cout << "Third vector (sum of f and s vectors): " << endl;
	c = a + b;
	c.outputDigits();

	cout << "Fourth vector: " << endl;
	d = d > c;
	d.outputDigits();

	cout << "Deciding which number is bigger (t and f vectors): " << endl;
	d.outputDigits();

}