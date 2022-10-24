#include<iostream>
#include<algorithm>
#include<chrono>
#include"ManageFiles.h"
using namespace std;
using namespace std::chrono;
void doInitialWork(const string fileNames[], const int fileSizes[],const int& size) {
    for(int i{0}; i < size; i++) {
        // {
            ManageFiles files;
            files.writeJobsToFile(fileNames[i], fileSizes[i]);
        // }
    }
}
template<class T>
void printArray(const vector<T>& arr) {
    for(int i{0}; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "\n--------------------\n";
}
void jobSchedulingBruteForce(const vector<string>& processNames, const vector<int>& startTimes, const vector<int>& finishTimes) {
    vector<string> maxProcesses;
    for(int i{0}; i < processNames.size(); i++) {
        vector<string> processes;
        processes.push_back(processNames[i]);
        int lastFinishTime = finishTimes[i];
        for(int j{i + 1}; j < processNames.size(); j++) {
            if(startTimes[j] > lastFinishTime) {
                processes.push_back(processNames[j]);
                lastFinishTime = finishTimes[j];
            }
        }
        if(maxProcesses.size() < processes.size()) {
            maxProcesses.clear();
            maxProcesses = processes;
        }
    }

    cout << "Max processes using brute force: " << maxProcesses.size() << "\n";
}

void bubbleSort(vector<string>& processNames, vector<int>& startTimes, vector<int>& finishTimes) {
    for(int i = 0; i < processNames.size(); i++) {
        for(int j = 1; j < processNames.size(); j++ ) {
            if(finishTimes[j] < finishTimes[j - 1]) {
                swap(finishTimes[j], finishTimes[j - 1]);
                swap(startTimes[j], startTimes[j - 1]);
                swap(processNames[j], processNames[j - 1]);
            }
        }
    }
}

void jobSchedulingGreedy(vector<string> processNames, vector<int> startTimes, vector<int> finishTimes) {
    bubbleSort(processNames, startTimes, finishTimes);
    vector<string> maxProcesses;
    maxProcesses.push_back(processNames[0]);
    int lastFinishTime = finishTimes[0];
    for(int i = 1; i < processNames.size(); i++) {
        if(startTimes[i] > lastFinishTime) {
            maxProcesses.push_back(processNames[i]);
            lastFinishTime = finishTimes[i];
        }
    }
    cout << "Max processes using greedy: " << maxProcesses.size() << "\n";
}

int main() {
    const string fileNames[] = {"five", "ten", "fifteen", "twenty", "twentyFive", "thirty"}; 
    const int fileSizes[] = {5, 10, 15, 20, 25, 30};
    doInitialWork(fileNames, fileSizes, 6);
    vector<string> processNames;
    vector<int> startTime;
    vector<int> finishTime;
    for(int i = 0; i < 6; i++) {
        {
            ManageFiles files;
            files.readJobsFromFile(fileNames[i], processNames, startTime, finishTime);
            auto start1 = high_resolution_clock::now();
            jobSchedulingBruteForce(processNames, startTime, finishTime);
            auto stop1 = high_resolution_clock::now();
            auto start2 = high_resolution_clock::now();
            jobSchedulingGreedy(processNames, startTime, finishTime);
            auto stop2 = high_resolution_clock::now();
            auto duration1 = duration_cast<microseconds>(stop1 - start1);
            auto duration2 = duration_cast<microseconds>(stop2 - start2);
            cout << "\n-----------------------------------------\n";
            cout << "Time for brute force: " << duration1.count() << "\n";
            cout << "Time for greedy approach: " << duration2.count() << "\n";
            cout << "\n-----------------------------------------\n";
            processNames.clear();
            startTime.clear();
            finishTime.clear();
        }
    }
    return 0;
}