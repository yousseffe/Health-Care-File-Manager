//
// Created by youssef on 11/30/2024.
//

#include "PrimaryIndex_Doctor.h"
void PrimaryIndex_Doctor::add(const string& key, int RNN) {
    if (index.find(key) == index.end()) {
        index[key] = RNN;
        Write_Index_To_File();
    }
}

int PrimaryIndex_Doctor::get(const string& key) {
    if (index.find(key) != index.end()) {
        return index[key];
    }
    return -1;
}

void PrimaryIndex_Doctor::Write_Index_To_File() {
    ofstream PK_Index_Doctor("PK_Index_Doctor.txt", ios::trunc); // Overwrite the file
    if (!PK_Index_Doctor.is_open()) {
        cerr << "Error: Unable to open file for writing.\n";
        return;
    }
    for (const auto& entry : index) {
        PK_Index_Doctor << left << setw(15) << entry.first << "|" << setw(2) << entry.second << "\n";
    }
    PK_Index_Doctor.close();
}

void PrimaryIndex_Doctor::Load_Index_From_File() {
    ifstream PK_Index_Doctor("PK_Index_Doctor.txt");
    if (!PK_Index_Doctor.is_open()) {
        cerr << "Error: Unable to open file for reading.\n";
        return;
    }
    string line;
    while (getline(PK_Index_Doctor, line)) {
        string key;
        int RNN;
        stringstream ss(line);
        getline(ss, key, '|');
        string newKey;
        for (int i = 0; i < key.length(); ++i) {
            if (key[i] != ' '){
                newKey += key[i];
            }
            else break;
        }
        ss >> RNN;

        if (!newKey.empty()) {
            index[newKey] = RNN;
        }
    }
    PK_Index_Doctor.close();
}

void PrimaryIndex_Doctor::display() {
    for (const auto& entry : index) {
        cout << "ID: " << entry.first << " -> Offset: " << entry.second << "\n";
    }
}