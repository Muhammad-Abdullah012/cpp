//Q iv.
#include<iostream>
using namespace std;
int main() {
    for(int i = 1000; i > 0; --i) {
        if( i % 2 == 0 && i % 3 == 0 && i % 5 != 0 && i % 7 != 0) {
            cout << i << "\n";
        }
    }
    return 0;
}