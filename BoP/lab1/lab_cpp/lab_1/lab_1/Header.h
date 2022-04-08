#pragma once

using namespace std;
ofstream createFile(string file_name);
void fillFile(string file_name, vector<string> inputText);
vector<vector<string>> split(string file_name);
vector<string> extractText(string file_name);
vector<int> findMinWord(vector<vector<string>> words, vector<string> &minWords);
vector<string> inputText(string file_name);
vector<string> createText(vector<vector<string>> splitedText, vector<string> minWords, vector<int> minLength);
void outputFile(string file_name);
