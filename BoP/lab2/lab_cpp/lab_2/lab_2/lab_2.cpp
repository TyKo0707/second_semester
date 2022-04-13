#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Header.h"
using namespace std;

int main() {

	string file_mode;
	cout << "Do you want to add text or rewrite file? (Enter 'a' if you want to add text; 'r' if you want to rewrite text): ";
	getline(cin, file_mode);

	string first_f = "calls_cpp.txt", second_f = "changed_calls.txt";
	int num_of_calls = 0;
	create_list(first_f, num_of_calls, file_mode);

	cout << "\nResult of writing first edition of file is: " << endl;
	show_res(first_f, num_of_calls);

	delete_cols(first_f, second_f, num_of_calls);

	cout << "\nResult of changing in file is: " << endl;
	show_res(second_f, num_of_calls);
}