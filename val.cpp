#include<iostream>
#include<iomanip>
using namespace std;
const int UptoThreeHrsCharges = 100;
const int OneDayCharges = 1000;
const int ExtraChargesPerHr = 50;
int calculateCharges(double &hours) {
    if(hours > 0 && hours <= 3) {
        return UptoThreeHrsCharges;
    }
    else if(hours == 24.0) {
        return OneDayCharges;
    }
    else {
        return UptoThreeHrsCharges + (hours - 3) * ExtraChargesPerHr;
    }
}
int main() {
    double hrs[3];
    int charges[3];
    int totalhrs = 0, totalCharges = 0;
    for(int i = 0; i < 3; i++) {
        cin >> hrs[i];
        totalhrs += hrs[i];
    }
    for(int i = 0; i < 3; i++) {
        charges[i] = calculateCharges(hrs[i]);
        totalCharges += charges[i];
    }
    cout << "Car" << setw(10) << "Hours" << setw(10) << "Charges\n";
    for(int i = 0; i < 3; i++) {
        cout << i+1 << setw(10) << hrs[i] << setw(10) << charges[i] << "\n";
    }
    cout << "Total" << setw(10) << totalhrs << setw(10) << totalCharges << "\n";
    return 0;
}