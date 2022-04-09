#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Header.h"

using namespace std;

ofstream createFile(string file_name) {

	ofstream file;
	file.open(file_name, ios::out | ios::trunc);

	if (!file.is_open()) {
		cout << "File isn't created" << endl;
	}
	else {}

	file.close();
	return file;
}

void fillFile(string file_name, vector<string> inputText) {

	ofstream file;
	file.open(file_name);

	for (int i = 0; i < inputText.size(); i++)
	{
		file << inputText[i];
		file << "\n";
	}

	file.close();
}

vector<string> inputText(string file_name) {

	vector<string> input;
	string str;

	cout << "Input text for " + file_name + ": " << endl;	
	while (getline(cin, str)) {
		input.push_back(str);
	}

	return input;
}

vector<string> createText(vector<vector<string>> splitedText, vector<string> minWords, vector<int> minLength) {
	vector<string> text;

	for (int i = 0; i < splitedText.size() - 1; i++)
	{
		string str;
		for (int j = 0; j < splitedText[i].size(); j++)
		{
			str += splitedText[i][j] + " ";
		}
		str += "(" + minWords[i] + "-";
		str += to_string(minLength[i]) + ")";
		text.push_back(str);
	}
	return text;
}

vector<string> extractText(string file_name) {

	vector<string> text;
	string str;
	ifstream file;
	file.open(file_name, ios::in);

	if (!file.is_open()) {
		cout << "Cannot open file!" << endl;
	}
	else {}
	
	while (!file.eof()) {
		getline(file, str);
		text.push_back(str);
	}

	file.close();

	return text;
}

vector<vector<string>> split(string file_name) {

	vector<vector<string>> splitedText;
	vector<string> text = extractText(file_name);

	for (int i = 0; i < text.size(); i++)
	{
		vector<string> words;
		string word, sti = text[i] + " ";
		for (int j = 0; j < sti.size(); j++) {
			if (!ispunct(sti[j]) && !isblank(sti[j])) {
				word += sti[j];
			}
			else {
				if (word != "") {
					words.push_back(word);
					word = "";
				}
				else {
					continue;
				}				
			}
		}
		splitedText.push_back(words);
	}
	
	return splitedText;
}

vector<int> findMinWord(vector<vector<string>> words, vector<string>& minWords) {
	vector<int> minLength;
	for (int i = 0; i < words.size() - 1; i++)
	{
		string min_word = words[i][0];
		int min_length = words[i][0].size();
		for (int j = 0; j < words[i].size(); j++) {
			if (min_word.size() >= words[i][j].size()) {
				min_word = words[i][j];
				min_length = words[i][j].size();
			}
		}
		minWords.push_back(min_word);
		minLength.push_back(min_length);
	}
	return minLength;
}

void outputFile(string file_name) {

	ifstream file;
	string str;
	file.open(file_name);
	
	while (getline(file, str)) {		
		cout << str << endl;;
	}

	file.close();
}