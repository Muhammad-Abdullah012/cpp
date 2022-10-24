#include <iostream>
#include <string>

class TextInput
{
    std::string value;
public:
    void add(char c) { 
        value.push_back(c);
    }

    virtual std::string getValue() { return value; }
};

class NumericInput : public TextInput {

public:
    std::string getValue() {
        std::string ans;
        std::string value = TextInput::getValue();
        for(int i = 0; i < value.size(); ++i) {
            int c = value[i];
            if(c >= 48 && c <= 57 ) {
                ans.push_back(value[i]);
            }
        }
        return ans;
    }
};

#ifndef RunTests
int main()
{
    TextInput* input = new NumericInput();
    input->add('1');
    input->add('a');
    input->add('0');
    std::cout << input->getValue();
}
#endif