#ifndef BIG_INT_H
#define BIG_INT_H

#include <iostream>
#include <bitset>

class BigInt {
    std::string _num;

    void equalStrLength(std::string&, const std::string&) const;
    public:
        BigInt(): _num("") {}   // default constructor
        BigInt(const std::string& s): _num(s) {}    // parameterized constructor
        BigInt(const BigInt& b) :_num(b.num()) {}   // Copy constructor
        
        std::string num() const { return _num; }    // Getter
        void setNum(const std::string&);            // Setter
        BigInt operator+(const BigInt&) const;
        friend std::ostream& operator<<(std::ostream& out, const BigInt&);
        friend std::istream& operator>>(std::istream& in, BigInt&);
};

#endif