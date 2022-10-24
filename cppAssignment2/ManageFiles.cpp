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

int ManageFiles::getValidFinishTime(const int& startTime, const int& size) {
    int finishTime;
    do {
        finishTime = rand() % size;
    } while(finishTime <= startTime);
    return finishTime;
}

void ManageFiles::writeJobsToFile(const string& fileName, const unsigned short int& size) {
    fout.open(fileName, ios::out);
    if(fout.is_open()) {
        srand(time(nullptr));
        for(int i{0}; i < size; i++) {
            int startTime = rand() % (size - 1);
            int finishTime = getValidFinishTime(startTime, size);
            fout << "p" << i + 1 << " ";
            fout << startTime << " " << finishTime;   //
            if(i < size - 1)
                fout << "\n";
        }
    }
    else {
        cout << "Cannot open file!\n";
    }
}
void ManageFiles::readJobsFromFile(const string& fileName, vector<string>& processName, vector<int>& startTime, vector<int>& finishTime) {
    fin.open(fileName, ios::in);
    if(fin.is_open()) {
        string input;
        string procName;
        int stTime, endTime;
        while(!fin.eof()) {
            fin >> procName >> stTime >> endTime;
            processName.push_back(procName);
            startTime.push_back(stTime);
            finishTime.push_back(endTime);
        }
    }
}