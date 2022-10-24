#include<iostream>
#include<numeric>
#include<vector>
using namespace std;

void stringToAscii(string s, vector<int>& ascii) {
    for(int i = 0; i < s.length(); ++i) {
        ascii.push_back((int)s[i]);
    }
    
}

void calculateDifference(string s, vector<int>& ascii, vector<int>& ans) {
    for(int i{0}; i < s.length(); ++i) {
        int asciiCode = (int) s[i];
        if(asciiCode <= ascii.at(0)) {
            ans.push_back(std::min(ascii.at(0) - asciiCode, std::abs(ascii.at(0) - asciiCode - 26)));
        } else if(asciiCode >= ascii.at(ascii.size() - 1)) {
            ans.push_back(std::min(asciiCode - ascii.at(ascii.size() - 1), std::abs(ascii.at(ascii.size() - 1) - asciiCode - 26)));
        } else {
            int min = std::min(std::abs(ascii.at(0) - asciiCode), std::abs(ascii.at(0) - asciiCode - 26));
            for(int j{1}; j < ascii.size(); ++j) {
                int diff = std::min(std::abs(ascii.at(j) - asciiCode), std::abs(ascii.at(j) - asciiCode - 26));
                if(diff < min) {
                    min = diff;
                }
            }
            ans.push_back(min);
        }
    }
}
void printVectorSum(vector<int>v) {
    // for(int i{0}; i < v.size(); ++i) {
    //     cout << v.at(i) << " ";
    // }
    // cout << "\n";
    cout << accumulate(v.begin(), v.end(), 0)<< "\n";
}
int main() {
    freopen ("output.txt","w",stdout);
    freopen ("input.txt","r",stdin);

    unsigned short int t;
    
    cin >> t;
    while(t > 0) {       
        string s, f; 
        vector<int> ans;
        vector<int>ascii;
        cin >> s;
        cin >> f;
        stringToAscii(f, ascii);
        calculateDifference(s, ascii, ans);
        printVectorSum(ans);
        
        --t;
    }
    
    
    
    return 0;
}