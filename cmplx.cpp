//Operator Overloading

#include<iostream>

using namespace std;

class Complex
{
public:
    int a,b;
    void input(string s)
    {
        int v1=0;
        unsigned int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        a=v1;
        b=v2;
    }
    string operator+(const Complex& );
    friend ostream& operator<<(ostream& out, const Complex&);
};

string Complex::operator+(const Complex& a) {
    string s = to_string(this->a + a.a) + "i" + to_string(this->b + a.b);
    return s;
}
ostream& operator<<(ostream& out, const Complex& a) {
    out << to_string(a.a) + "+ i" + to_string(a.b) << "\n";
    return out;
}
//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"

int main()