#include<iostream>
int main() {
    unsigned int l, r;
    std::cin >> l >> r;
    for(; l <= r; ++l) {
        if(l & 1)
            std::cout << l << " ";
    }
    return 0;
}