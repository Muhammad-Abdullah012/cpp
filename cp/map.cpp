#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main() {
    std::map<string, string> contacts;
    unsigned int t;
    string str;
    freopen ("output.txt","w",stdout);
    freopen ("input.txt","r",stdin);
    cin >> t;
    cin.ignore();
    while(t--) {
        getline(cin, str);
        contacts[str.substr(0,str.length() - 9)] = str.substr(str.length() - 8, str.length());
    }
    while(getline(cin, str)) {
        auto search = contacts.find(str);
        if(search != contacts.end()) {
            cout << search->first << "=" << search->second;
        }
        else {
            cout << "Not found";
        }
        cout << "\n";
    }
    return 0;
}