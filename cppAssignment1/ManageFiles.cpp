#include<iostream>
#include<vector>
#include"ManageFiles.h"
using std::ios;
using std::string;
using std::cout;
using std::vector;

//Constructor
ManageFiles::ManageFiles() {
    
}

void ManageFiles::writeRandomNumbersToFile(const string& fileName, const unsigned short int& size) {
    fout.open(fileName, ios::out);
    if(fout.is_open()) {
        srand(time(nullptr));
        unsigned short int initial{2001}, finale{1000};
        for(int i{0}; i < size; i++) {
            fout << rand() % initial - finale;  //calculate random num from 0 to 2001 and subtract 1000 for -ve values
            if(i < size - 1)
                fout << "\n";
        }
    }
    else {
        cout << "Cannot open file!\n";
    }
}
void ManageFiles::readNumbersFromFile(const string& fileName, vector<int>& values) {
    fin.open(fileName, ios::in);
    if(fin.is_open()) {
        int input;
        while(!fin.eof()) {
            fin >> input;
            values.push_back(input);
        }
    }
}