//Q3 (d):
#include<iostream>
using namespace std;
int main() {
    int val1 = 8, val2 = 12;
    for(;val1 > 1 && val2 < 15;) {
        cout << val1 + val2 << "\t";
        val1 = val1 - 3;
        val2 = val2 + 2;
    }
    return 0;
}
//output:
//20      19      