#include "materialPoint.h"

int findMax(vector<double> distances) {
	int ind = 0;
	for (int i = 0; i < distances.size(); i++)
	{
		if (distances[ind] <= distances[i]) {
			ind = i;
		}
	}
	return ind;
}
