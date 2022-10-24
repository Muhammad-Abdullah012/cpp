#include<iostream>
#include<algorithm>
#include<assert.h>
#include"BigInt.h"

using std::string;
using std::cerr;

constexpr int ASCII_CODE_ZERO = 48;


void BigInt::setNum(const std::string& s) {
    this->_num = s;
}

std::ostream& operator<< (std::ostream& out, const BigInt& data) {
    out << data.num();
    return out;
}
std::istream& operator>> (std::istream& in, BigInt& num) {
    std::string input{};
    in >> input;
    num.setNum(input);
    return in;
}

void BigInt::equalStrLength(string& s1, const string& s2) const {
    if(s1.length() >= s2.length())
      return;
    std::reverse(s1.begin(), s1.end());
    int l = abs(s1.length() - s2.length());
    while(l > 0) {
        if(s1.length() < s2.length()) {
            s1.push_back('0');
        }
        --l;
    }
    std::reverse(s1.begin(), s1.end());
}

BigInt BigInt::operator+(const BigInt& n) const {
    BigInt ans;
    string result{};
    string num = this->_num;
    string num2 = n.num();

    // cerr << "num before: " << num << " num2 before: " << num2 << "\n";
    // cerr << "num after: " << num << " num2 after: " << num2 << "\n";
    if(num.length() > num2.length())
        this->equalStrLength(num2, num);
    else
        this->equalStrLength(num, num2);

    // Now length of "num" and "num2" are equal....
    int carry{};
    // cerr << "num length: " << num.length() << "\n";
    for(auto it = num.rbegin(); it != num.rend(); it = std::next(it)) {
        // assert(i >= 0 && i < num.length());
        // cerr << *it << "\n";
        int a = (int) *it - ASCII_CODE_ZERO;
        int index = distance(num.rbegin(), it);
        int b = (int) *(std::next(num2.rbegin(), index)) - ASCII_CODE_ZERO;
        // cerr << "a: " << a << "b: " << b << "\n";
        int sum = a + b + carry;
        string temp = std::to_string(sum);
        if(temp.length() > 1) {
            result.push_back(temp.at(1));
            carry = std::stoi(temp.substr(0, 1));
            // cerr << "result: " << result << "\n";
            // cerr << "carry: " << carry << "\n";
        } else {
            result.push_back(temp.at(0));
            carry = 0;
        }
        // cerr << "result: " << result << "\n";
    }
    if(carry) {
        result.append(std::to_string(carry));
    }
    std::reverse(result.begin(), result.end());
    ans.setNum(result);
    return ans;
}
