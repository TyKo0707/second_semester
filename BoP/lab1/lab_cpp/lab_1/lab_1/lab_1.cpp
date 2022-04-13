#include<iostream>
#include <fstream>
#include <string>
#include <vector>
#include"Header.h"
using namespace std;

int main()
{
	string file_mode;
	cout << "Do you want to add text or rewrite file? (Enter 'a' if you want to add text; 'r' if you want to rewrite text): ";
	getline(cin, file_mode);

	string file1_p = "file_1.txt", file2_p = "file_2.txt";
	ofstream file1 = createFile(file1_p, file_mode);
	fillFile(file1_p, file_mode);

	vector<vector<string>> splitedText = split(file1_p);

	vector<string> minWords;
	vector<int> minLength = findMinWord(splitedText, minWords);
	
	ofstream file2 = createFile(file2_p, file_mode);
	vector<string> text2 = createText(splitedText, minWords, minLength, file2_p);
	cout << "\nFile after changes: " << endl;
	outputFile(file2_p);
}