#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'nonDivisibleSubset' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */
void print(const vector<int>& v) {
    cerr << "Print\n";
    std::for_each(v.begin(), v.end(), [] (const int& n) { cerr << n << " "; });
    cerr << "\n";
}

void RemoveZeros(vector<int>& v) {
    int zeros = std::count(v.begin(), v.end(), 0);
    while(zeros > 1) {
        auto it = std::find(v.begin(), v.end(), 0);
        v.erase(it);
        --zeros;
    }
}

void RemoveHalfK(vector<int>& v, const int& k) {
    int halfK = std::count(v.begin(), v.end(), k / 2);
    while( halfK > 1) {
        auto it = std::find(v.begin(), v.end(), k / 2);
        v.erase(it);
        --halfK;
    }
}

// void RemoveIt(vector<int>& v,const int& value , int& iterator) {
//     std::cerr << "Removing: " << value << "\n";
//     std::cerr << "Count: " << iterator << "\n";
//     while(iterator > 0) {
//         auto it = std::find(v.begin(), v.end(), value);
//         std::cerr << "index: " << std::distance(v.begin(), it);
//         v.erase(it);
//         --iterator;
//     }
//     print(v);
// }

void RemoveComplements(vector<int>& v, const int& k) {
    std::cerr << "Before: \n";
    print(v);
    vector<int> temp;
    for(int i{0}; i < v.size(); ++i) {
        if(std::find(temp.begin(), temp.end(), v.at(i)) == temp.end())  {
            temp.push_back(v.at(i));
            int a = std::count(v.begin(), v.end(), v.at(i));
            int b = std::count(v.begin(), v.end(), k - v.at(i));
            if(a > b && b > 0) {
                int value = k - v.at(i);
                v.erase(std::remove(v.begin(), v.end(), value), v.end());
            }
            else if(b > a && a > 0) {
                int value = v.at(i);
                v.erase(std::remove(v.begin(), v.end(), value), v.end());
            } else {
                continue;
            }
            
        } else {
            continue;
        }
    }
}

int nonDivisibleSubset(int k, vector<int> s) {
    vector<int> ans(s.size());
    for(int i{0}; i < s.size(); ++i) {
        ans.at(i) = s.at(i) % k;
    }
    print(ans);
    RemoveZeros(ans);
    if(k % 2 == 0) {
        RemoveHalfK(ans, k);
    }
    
    RemoveComplements(ans, k);
    print(ans); 
    return ans.size();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));

    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    int result = nonDivisibleSubset(k, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
