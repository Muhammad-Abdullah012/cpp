#include<iostream>
#include<vector>
using namespace std;
void display(const vector<unsigned int>& list) {
    for(unsigned int i{0}; i < list.size(); i++) {
        cout << list.at(i) << " ";
    }
}
int main() {
    unsigned int n;
    vector<unsigned int> list;
    cin >> n;
    for(unsigned int i{0}; i < n; i++) {
        unsigned int v;
        cin >> v;
        list.push_back(v);
    }
    for(unsigned int i = 0, j = n - 1; i < j; i++ ) {
        unsigned int v = list.at(i);
        list.at(i) = list.at(j);
        list.at(j) = v;
        j--;
    }
    display(list);
    return 0;
}