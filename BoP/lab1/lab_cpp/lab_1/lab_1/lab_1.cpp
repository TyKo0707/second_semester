#include<iostream>
#include <fstream>
#include <vector>
#include"Header.h"
using namespace std;

int main()
{
	string file1_p = "file_1.txt", file2_p = "file_2.txt";
	ofstream file1 = createFile(file1_p);
	vector<string> text1 = inputText(file1_p);
	fillFile(file1_p, text1);

	vector<vector<string>> splitedText = split(file1_p);

	vector<string> minWords;
	vector<int> minLength = findMinWord(splitedText, minWords);
	
	ofstream file2 = createFile(file2_p);
	vector<string> text2 = createText(splitedText, minWords, minLength);
	fillFile(file2_p, text2);
	cout << "\nFile after changes: " << endl;
	outputFile(file2_p);
}