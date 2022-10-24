#include<bits/stdc++.h>
using namespace std;
class BadLengthException : public exception {
    int n;
    public:
        BadLengthException(int n=0) {
            this->n = n;
        }
        const char * what () const throw () {
            return to_string(n).c_str();
        }
};