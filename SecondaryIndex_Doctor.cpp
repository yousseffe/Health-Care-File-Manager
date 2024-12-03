//
// Created by youssef on 11/30/2024.
//

#include "SecondaryIndex_Doctor.h"
void SecondaryIndex_Doctor::add(const string& Name, string id) {
    auto& ids = index[Name];
    if (find(ids.begin(), ids.end(), id) != ids.end()) {
        return;
    }
    index[Name].push_back(id);
    Write_Index_To_File();
}
list<string> SecondaryIndex_Doctor::get(const  string& Name) {
    if (index.find(Name) != index.end()) {
        return index[Name];
    }
    return {};
}
void SecondaryIndex_Doctor::Write_Index_To_File() {
    ofstream SK_Index_Doctor("SK_Index_Doctor.txt", ios::trunc);
    if (!SK_Index_Doctor.is_open()) {
        cerr << "Error: Unable to open file for writing.\n";
        return;
    }
    for (const auto& entry : index) {
        for(const auto& ID: entry.second) {
            SK_Index_Doctor << left << setw(30) << entry.first << "|" << setw(15) << ID<< "\n";
        }
    }
    SK_Index_Doctor.close();
}

void SecondaryIndex_Doctor::Load_Index_From_File() {
    ifstream SK_Index_Doctor("SK_Index_Doctor.txt");
    if (!SK_Index_Doctor.is_open()) {
        cerr << "Error: Unable to open file for reading.\n";
        return;
    }
    string line;
    while (getline(SK_Index_Doctor, line)) {
        string Name;
        string ID;

        stringstream ss(line);
        getline(ss, Name, '|');

        ss >> ID;

        if (!Name.empty()) {
            index[Name].push_back(ID);
        }
    }

    SK_Index_Doctor.close();
}

void SecondaryIndex_Doctor::display() {
    for (const auto& entry : index) {
        cout << "Key: " << entry.first << " -> ID: ";
        for (string ID : entry.second) {
            cout << ID << " ";
        }
        cout << "\n";
    }
}