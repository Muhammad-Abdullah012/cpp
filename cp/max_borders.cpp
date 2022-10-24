#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test_cases;
    vector<int> results;
    cin >> test_cases;
    while(test_cases--) {
        int count{0}, maxCount{0};
        size_t findBlack, findWhite;
        int rows, cols;
        cin >> rows >> cols;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for(int i = 0; i < rows; i++) {
            string s;
            getline(cin, s);
            findBlack = s.find('#');
            if(findBlack != string::npos) {
                findWhite = s.find('.', findBlack + 1);
                if(findWhite != string::npos) {
                    count = findWhite - findBlack;
                }
                else {
                    count = cols - findBlack;
                }
                if(maxCount < count) {
                    maxCount = count;
                }
                count = 0;
            }
            else {
                count = 0;
            }
        }
        results.push_back(maxCount);
    }
    for(int i = 0; i < results.size(); i++) {
        cout << results.at(i) << "\n";
    }
    return 0;
}