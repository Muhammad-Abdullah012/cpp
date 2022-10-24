#include<iostream>
#include<vector>
#include<string>
#include"stringOp.hpp"

using std::string;
using std::vector;
using std::cout;

vector<string> String::split(const string& str, const string& ch) {
    vector<string> result;
    if(str.find(ch) == string::npos) {
        //if no match found, find return string::npos
        result.push_back(str);
    }
    else {
        size_t index{0}, prevIndex{0};
        while(true) {
            index = str.find(ch, prevIndex);
            if(index == string::npos) {
                //if no match found, find method returns string::npos
                result.push_back(str.substr(prevIndex));
                break;
            }
            result.push_back(str.substr(prevIndex, index - prevIndex));
            prevIndex = index + ch.size();
        }
    }
    return result;
}