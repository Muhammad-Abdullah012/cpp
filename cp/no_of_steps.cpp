#include <bits/stdc++.h>
using namespace std;
int main() {
	unsigned short int n;
	int count{0};
	cin >> n;
	vector<unsigned short int>a(n);
	vector<unsigned short int>b(n);
	
	for(unsigned short int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(unsigned short int i = 0; i < n; i++) {
		cin >> b[i];
	}
	unsigned short int minimumA = *min_element(a.begin(), a.end());
	unsigned short int minimumB = *min_element(b.begin(), b.end());
	unsigned short int val{0};
	for(unsigned int i = 0; i < a.size(); i++) {
		if(b.at(i) == minimumB) {
			val = a.at(i);
		}
	}
	for(;;) {
		val -= minimumB;
		if(val == minimumA) {
			count++;
		}
		if(val < minimumA) {
			break;
		}
	}
	cout << count << "\n";
	return 0;
}