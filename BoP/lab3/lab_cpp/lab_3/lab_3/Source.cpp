#include "Header.h"

void create(int n) {
	int x, y, z, rad;	
	vector <Sphere>v1;
	for (int i = 0; i < n; i++) {
		cout << "Enter x,y,z of center of sphere and it's radius: " << endl;
		cout << "x="; cin >> x;
		cout << "y="; cin >> y;
		cout << "z="; cin >> z;
		cout << "rad="; cin >> rad;
		v1.push_back(Sphere(x, y, z, rad));
	}
	cout << endl << "Spheres are: ";
	for (int i = 0; i < n; i++) {
		v1[i].printsp(i + 1);
	}
	belong(v1, n);
}

void belong(vector<Sphere> v1, int n) {
	int a, b, c, j;
	cout << endl << endl << "Enter x,y,z of point: " << endl;
	cout << "x="; cin >> a;
	cout << "y="; cin >> b;
	cout << "z="; cin >> c;
	cout << endl;
	vector<int> belong;
	for (int i = 0; i < n; i++) {
		j = v1[i].pointsp(a, b, c);
		if (j == 1) {
			belong.push_back(i + 1);
		}
	}
	if (belong.size() != 0) {
		stringstream ss;
		copy(belong.begin(), belong.end(), ostream_iterator<int>(ss, ","));
		string s = ss.str();
		s = s.substr(0, s.length() - 1);
		cout << "The point is inside the sphere(s) with number: " << s << endl;
	}
	else {
		cout << "The point is not inside the spheres" << endl;
	}
}