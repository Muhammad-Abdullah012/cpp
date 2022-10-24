#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned int n;
    vector<unsigned int> vect;

    freopen ("output.txt","w",stdout);
    freopen ("input.txt","r",stdin);
    cin >> n;
    for(unsigned int i = 0, j; i < n; i++) {
        cin >> j;
        vect.push_back(j);
    }
    for(auto i = vect.begin(); i != vect.end(); i++) {
        cout << *i << " ";
    }
    cout << "\n--------------------\n";
    //Reverse vector
    reverse(vect.begin(), vect.end());
    for(auto i = vect.begin(); i != vect.end(); i++) {
        cout << *i << " ";
    }
    return 0;
}
