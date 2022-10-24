#include<iostream>
#include<vector>
#include"stringOp.hpp"
using namespace std;
void printArray(const vector<string>& arr) {
    for(int i{0}; i < arr.size(); ++i) {
        cout << arr.at(i) << "\n";
    }
}

int main() {
    string str = "abc.def.ghi";
    vector<string> result = String::split(str, ".");
    cout << str << " :\n";
    printArray(result);
    string str2 = "abcd..def..ghij..k";
    result = String::split(str2, "..");
    cout << str2 << " :\n";
    printArray(result);
    result = String::split("abcdef", "@");
    printArray(result);
    return 0;
}