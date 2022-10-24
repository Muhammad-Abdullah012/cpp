#include<iostream>
using namespace std;
int main() {
    int x = 2, y = 5;
    x *= ++x;
    cout << x;
   return 0;
}