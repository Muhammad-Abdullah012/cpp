/*
1-  Generate Random number from -1000 to 1000
2-  populate those random numbers in 10 different files
3-  each file contain elements of array
4-  each file should have atleast 50 -ve numbers
5-  file sizes are n = 100, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000
6-  program should read each file
7-  and find maximum sub array using
    i)  Brute force
    ii) Divide and Conquer
8-  
*/
#include<iostream>
#include<vector>
#include<chrono>
#include"ManageFiles.h"
using namespace std;
using namespace std::chrono;


void doInitialWork(const string fileNames[],const int fileSizes[],const int& size) {
    for(int i{0}; i < size; i++) {
        {
            ManageFiles files;
            files.writeRandomNumbersToFile(fileNames[i], fileSizes[i]);
        }
    }
}

int maxSubArrayBruteForce(const vector<int>& arr, int& start, int& end) {
    int maxSum = arr[start];
    for(int i{0}; i < arr.size() - 2; i++) {
        int sum = arr[i];
        for(int j{i + 1}; j < arr.size() -1; j++) {
            sum += arr[j];
            if(maxSum < sum) {
                maxSum = sum;
                start = i;
                end = j;
            }
        }
    }
    return maxSum;
}
int maxCrossSubArrayDivideAndConquer(const vector<int>&arr,const int& start, int& mid,const int& end) {
    int leftSum = 0, rightSum = 0;
    for(int i = mid, sum = 0; i >= start; i--) {
        sum += arr[i];
        if(sum > leftSum) {
            leftSum = sum;
        }
    }
    for(int i = mid + 1, sum = 0; i <= end; i++) {
        sum += arr[i];
        if(sum > rightSum) {
            rightSum = sum;
        }
    }
    return leftSum + rightSum;
}
int maxSubArrayDivideAndConquer(const vector<int>& arr,const int& start,const int& end) {
    if(start == end) {
        return arr[start];
    }
    else {
        int mid = (start + end) / 2;
        int leftSum = maxSubArrayDivideAndConquer(arr, start, mid);
        int rightSum = maxSubArrayDivideAndConquer(arr, mid + 1, end);
        int midSum = maxCrossSubArrayDivideAndConquer(arr, start, mid, end);
        
        if(leftSum > rightSum && leftSum > midSum) {
            return leftSum;
        }
        else if(rightSum > leftSum && rightSum > midSum) {
            return rightSum;
        }
        else {
            return midSum;
        }
    }
}
int main() {
    const string fileNames[] = {"data0.txt", "data1.txt", "data2.txt", "data3.txt", "data4.txt", "data5.txt", "data6.txt", "data7.txt", "data8.txt", "data9.txt"};
    const int fileSizes[] = {100, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000};
    vector<int> values;
    int start{0}, end{0};
    doInitialWork(fileNames, fileSizes, 10);
    for(int i{0}; i < 10; i++) {
        {
            ManageFiles files;
            files.readNumbersFromFile(fileNames[i], values);
            cout << fileNames[i] << " file.\n";
            end = values.size() - 1;
            auto start1 = high_resolution_clock::now();
            cout << "Max sum using Divide and conquer is: " << maxSubArrayDivideAndConquer(values, start, end) << "\n";
            auto stop1 = high_resolution_clock::now();
            auto start2 = high_resolution_clock::now();
            cout << "Max sum using brute force is: " << maxSubArrayBruteForce(values, start, end) << "\nStart index of max sub-array: " << start << "\nEnd index of max sub-array: " << end << "\n";
            auto stop2 = high_resolution_clock::now();
            cout << "\n-----------------------------------------------------------\n";
            auto duration1 = duration_cast<microseconds>(stop1 - start1);
            auto duration2 = duration_cast<microseconds>(stop2 - start2);
            cout << "Time for Divide and Conquer approach: " << duration1.count() << " microseconds\n";
            cout << "Time for Brute force approach: " << duration2.count() << " microseconds\n";
            cout << "-----------------------------------------------------------\n";
            values.clear();
        }
    }
    return 0;
}