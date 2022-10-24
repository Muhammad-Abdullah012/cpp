#include<iostream>
#include<algorithm>
#include<vector>
#include<assert.h>
using namespace std;

template<class T>
void printArray(const T arr[], const int& size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
template<class T>
void printVector(const vector<T>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void merge_Arrays(int arr[], const int& low, const int& mid, const int& high) {
    vector<int>leftArray, rightArray;
    for(int i = low; i <= mid; i++) {
        leftArray.push_back(arr[i]);
    }
    for(int i = mid + 1; i <= high; i++) {
        rightArray.push_back(arr[i]);
    }
    int i = low, j = mid + 1;
    int leftArrayIdx = 0, rightArrayIdx = 0;
    for( ; leftArrayIdx < leftArray.size() && rightArrayIdx < rightArray.size() ; ) {
        if(leftArray.at(leftArrayIdx) <= rightArray.at(rightArrayIdx)) {
            arr[i] = leftArray.at(leftArrayIdx);
            i++;
            leftArrayIdx++;
        }
        else {
            arr[j] = rightArray.at(rightArrayIdx);
            j++;
            rightArrayIdx++;
        }
    }
    // printArray(arr, 6);
    // while(leftArrayIdx < leftArray.size()) {
    //     arr[i] = leftArray.at(leftArrayIdx);
    //     i++;
    //     leftArrayIdx++;
    // }
    // while(rightArrayIdx < rightArray.size()) {
    //     arr[j] = rightArray.at(rightArrayIdx);
    //     j++;
    //     rightArrayIdx++;
    // }
    
}

void merge_sort(int arr[], const int& low, const int& high) {
    if(low < high) {
        int mid = low + (high - low) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge_Arrays(arr, low, mid, high);
    }
    else 
        return;
}

void insertion_sort(int arr[], const int& size) {
    for(int i = 1; i < size; i++) {
        for(int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
            swap(arr[j], arr[j - 1]);
        }
    }
}

int main() {

    int arr[] = {2,3,1,0,5,6};
    // insertion_sort(arr, 6);
    merge_sort(arr, 0, 5);
    printArray(arr, 6);
    for(int i = 0; i < 5; i++) {
        // assert(arr[i] < arr[i + 1]);
    }

    return 0;
}