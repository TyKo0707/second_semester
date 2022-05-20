#include <iostream>
#include <vector>
#include <stdlib.h> 
#include <stdio.h>
#include <time.h> 
#include "materialPoint.h"
#include "Header.h"

using namespace std;

int main() {
	int k, n;
	float t;
	vector<vector<double>> coords;
	vector<double> distances;
	srand(time(NULL));
	cout << "Input k: "; cin >> k;
	cout << "Input n: "; cin >> n;
	cout << "Input t: "; cin >> t;
	
	vector<materialPointX> x;
	for (int i = 0; i < k; i++)
	{
		materialPointX* cl = new materialPointX(t);
		x.push_back(*cl);
		cout << "Coordinates: " << endl;  x[i].getCoordinates();
		for (int j = 0; j < i; j++)
		{
			double d = x[i].getDistance(&x[j]);
			vector<double> dc = {x[i].getX(), x[i].getY(), x[j].getX(), x[j].getY()};
			coords.push_back(dc);
			distances.push_back(d);
		}
	}

	vector<materialPointXY> xy;
	for (int i = 0; i < n; i++)
	{
		materialPointXY* cl = new materialPointXY(t);
		xy.push_back(*cl);
		cout << "Coordinates: " << endl;  xy[i].getCoordinates();
		for (int j = 0; j < i; j++)
		{
			double d = xy[i].getDistance(&xy[j]);
			vector<double> dc = { xy[i].getX(), xy[i].getY(), xy[j].getX(), xy[j].getY() };
			coords.push_back(dc);
			distances.push_back(d);
		}
	}

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			double d = x[i].getDistance(&xy[j]);
			vector<double> dc = { x[i].getX(), x[i].getY(), xy[j].getX(), xy[j].getY() };
			coords.push_back(dc);
			distances.push_back(d);
		}
	}

	int ind = findMax(distances);
	cout << "Max distance: " << distances[ind] << endl;
	cout << "Between points with coordinates: (" << coords[ind][0] << ";" << coords[ind][1] << "), (" << coords[ind][2] << ";" << coords[ind][3] << ")" << endl;

}
