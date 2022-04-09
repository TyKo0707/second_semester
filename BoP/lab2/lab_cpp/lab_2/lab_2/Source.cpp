#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
#include "Header.h"
using namespace std;

struct cl {
    string tel_number, start_time, end_time;
    double price;
};

void show_res(string file_name) {
    cl c;
    ifstream file(file_name, ios::binary);
    while (file.read((char*)&c, sizeof(cl))) {
        cout << "\nPhone number: +380" << c.tel_number << endl;
        cout << "Call started: " << c.start_time << endl;
        cout << "Call ended: " << c.end_time << endl;
        cout << "Price of call: " << c.price << endl;
    }
    file.close();
}

double price_for_call(string start_time, string end_time) {

    int hours_s, mins_s, hours_e, mins_e;
    char extra;

    std::stringstream ss_start, ss_end;
    ss_start << start_time;
    ss_start >> hours_s >> extra >> mins_s >> extra;
    ss_end << end_time;
    ss_end >> hours_e >> extra >> mins_e >> extra;

    double diff = (hours_e * 60 + mins_e) - (hours_s * 60 + mins_s);

    if (hours_s >= 9 && hours_s <= 20) {
        return diff * 1.5;
    }
    else {
        return diff * 0.9;
    }
}

void delete_cols(string file_name_1, string file_name_2) {

    ifstream file(file_name_1, ios::binary);
    ofstream file2(file_name_2, ios::binary);
    vector<cl> cls;
    cl c;
    int count = 0;

    while (file.read((char*)&c, sizeof(cl))) {
        count++;
        int hours_s, mins_s, hours_e, mins_e;
        char extra;

        std::stringstream ss_start, ss_end;
        ss_start << c.start_time;
        ss_start >> hours_s >> extra >> mins_s >> extra;
        ss_end << c.end_time;
        ss_end >> hours_e >> extra >> mins_e >> extra;
        double diff = (hours_e * 60 + mins_e) - (hours_s * 60 + mins_s);
        if (diff <= 3) {
            cls.erase(cls.begin() + count);
        }
    }
    for (int i = 0; i < cls.size(); i++)
    {
        c = cls[i];
        file2.write((char*)&c, sizeof(cl));
    }
    file.close();
    file2.close();
}

void create_list(string file_name) {

    vector<cl> calls;
    ofstream file(file_name, ios::binary);
    string buf = "y";
    int count = 0;
    bool is_ok = true;

    while (buf == "y") {
        is_ok = true;
        count++;
        cl c;
        cout << "Client " << count << endl;
        cout << "Telephone number +380";
        cin >> c.tel_number;
        cin.ignore();
        cout << "Start time (HH:MM): ";
        cin >> c.start_time;
        cin.ignore();
        cout << "End time (HH:MM): ";
        cin >> c.end_time;
        cin.ignore();
        c.price = price_for_call(c.start_time, c.end_time);

        if (c.price < 0) {
            cout << "Mismatch in time!" << endl;
            is_ok = false;
        }
        if (is_ok) {
            file.write((char*)&c, sizeof(cl));
            calls.push_back(c);
        }
        cout << "Add another client? y/n: ";
        cin >> buf;
        cin.ignore();
    }
    file.close();
}