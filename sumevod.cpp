#include<iostream>
using namespace std;
int main() {
    unsigned int n;
    unsigned long int SumOdd{0}, SumEven{0};
    cin >> n;
    for(unsigned int i{1}, j{n}; j > 0 ; i++ ) {
        if(i&1) {
            SumOdd += i;
            j--;
        }
    }
    for(unsigned int i{1}, j{n}; j > 0 ; i++ ) {
        if(!(i&1)) {
            SumEven += i;
            j--;
        }
    }
    cout << SumOdd << " " << SumEven;
    return 0;
}