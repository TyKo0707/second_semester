#pragma once

using namespace std;
ofstream createFile(string file_name, string file_mode);
void fillFile(string file_name, string file_mode);
vector<vector<string>> split(string file_name);
vector<string> extractText(string file_name);
vector<int> findMinWord(vector<vector<string>> words, vector<string> &minWords);
vector<string> createText(vector<vector<string>> splitedText, vector<string> minWords, vector<int> minLength, string file_name);
void outputFile(string file_name);
