#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Detail {
	string detail;
	int amount;
	string provider;
	Detail* left;
	Detail* right;
	void print_detail();
	Detail() {
		detail = "";
		amount = 0;
		provider = "";
		left = 0;
		right = 0;
	}
};

void add_detail(Detail*& newOne, Detail*& current);

void output_tree(Detail*& current);

void getInfoProviders(Detail*& current, vector<int>& detailamount, int& i, vector<string>& providers);

string biggestProvider(int& max, Detail* root, int n);