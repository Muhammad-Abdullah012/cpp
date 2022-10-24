#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    freopen ("output.txt","w",stdout);
    freopen ("input.txt","r",stdin);
    unsigned int n, q;
    vector<string> v;
    vector<map<string, string>> vect;
    cin >> n >> q;
    cin.ignore();
    while(n--) {
        string s;
        getline(cin, s);
        v.push_back(s);
    }
    for(unsigned int i{0}; i < v.size(); ++i) {
        remove();
        // while(getline())
    }
    return 0;
}
