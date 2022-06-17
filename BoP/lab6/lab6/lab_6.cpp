#include "Tree.h"
#include <iostream>
#include <string>
using namespace std;


int main() {
	
	int n = 0;
	char enterNewDetail;
	Detail* root = NULL;
	Detail* current = new Detail;
	current = root;
	cout << "Do you want to add new detail?(y/n): "; cin >> enterNewDetail;

	while (tolower(enterNewDetail) != 'n') {
		Detail* nItem = new Detail;
		cin.ignore();
		cout << endl << "Detail name: ";
		getline(cin, nItem->detail);
		cout << endl << "Amount: ";
		cin >> nItem->amount;
		cin.ignore();
		cout << endl << "Provider: ";
		getline(cin, nItem->provider);
		if (n == 0) {
			root = nItem;
			current = nItem;
		}
		else {
			add_detail(nItem, root);
		}
		n++;

		cout << endl << "Do you want to add new detail?(Y/N): ";
		cin >> enterNewDetail;
	}

	output_tree(root);

	int maxNumDetails;
	string bestProvider = biggestProvider(maxNumDetails, root, n);
	cout << endl << "Provider with a most amount of details is: " << bestProvider << " with details amount: " << maxNumDetails;
}