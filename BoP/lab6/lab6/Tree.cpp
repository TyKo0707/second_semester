#include "Tree.h"

void Detail::print_detail() {
	cout << endl << "Name: " << detail << "  Amount: " << amount << "  Provider: " << provider;
}

void add_detail(Detail* &newOne, Detail* &current) {
	Detail* p = new Detail;
	p = newOne;
	if (current) {
		if (p->detail > current->detail) {
			add_detail(newOne, current->right);
		}
		else if (p->detail < current->detail) {
			add_detail(newOne, current->left);
		}
	}
	else {
		current = newOne;
	}
}

void output_tree(Detail*& current) {
	Detail* p = new Detail;
	p = current;
	if (p) {
		p->print_detail();

		output_tree(p->left);
		output_tree(p->right);
	}
}

void getInfoProviders(Detail*& current, vector<int>&detailamount, int &i, vector<string>&providers) {
	Detail* p = new Detail;
	p = current;
	if (p) {
		providers[i]=p->provider;
		detailamount[i] = p->amount;
		i++;
		getInfoProviders(p->left,detailamount,i,providers);
		getInfoProviders(p->right, detailamount, i, providers);
	}
}

string biggestProvider(int& max, Detail* root, int n) {
	vector<int>detailamount(n);
	int i = 0;
	vector<string>providers(n);

	getInfoProviders(root, detailamount, i, providers);

	auto iter = detailamount.cbegin();
	auto iter2 = providers.cbegin();

	for (int i = 0; i < detailamount.size(); i++) {
		for (int j = i + 1; j < detailamount.size(); j++) {
			if (providers[i] == providers[j]) {
				detailamount[i] += detailamount[j];
				detailamount.erase(iter + j);
				providers.erase(iter2 + j);
			}
		}
	}

	int temp;
	int temp_index;
	int max_index;
	max = *max_element(detailamount.begin(), detailamount.end());
	for (int i = 0; i < detailamount.size(); i++) {
		if (detailamount[i] == max) {
			max_index = i;
		}
	}

	return providers[max_index];
}