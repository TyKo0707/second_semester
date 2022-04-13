#pragma once
void create_list(std::string file_name, int& num_of_calls, std::string file_mode);
double price_for_call(std::string start_time, std::string end_time);
void delete_cols(const std::string& file_name_1, const std::string& file_name_2, int& num_of_calls);
void show_res(const std::string& file_name, int num_of_calls);
int num_of_structs(const std::string& file_name);
struct cl;
