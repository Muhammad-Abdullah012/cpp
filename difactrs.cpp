#include<iostream>
#include<vector>
using namespace std;
void display(vector<unsigned int>& v) {
    for(unsigned int i{0}; i < v.size(); ++i) {
        cout << v.at(i) << " ";
    }
}
void find_factors(vector<unsigned int>& v, const unsigned int &n) {
    for(unsigned int i{1}; i <= n; i++) {
        if(n%i == 0) {
            v.push_back(i);
        }
    }
}
int main() {
    vector<unsigned int> factors;
    unsigned int n;
    cin >> n;
    find_factors(factors, n);
    cout << factors.size() << "\n";
    display(factors);
    return 0;
}