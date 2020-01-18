#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
using ll = long long;

int main() {
	string S;
	cin >> S;
	// 00000 -> 01010
	// 00011 -> 01010
	// 000000 -> 010101
	// 0000000 -> 0101010
	// 00000000 -> 01010101
	int total_matched = 0;
	for (int x=0; x<2; ++x) {
		char left, right;
		if (x==0) {
			left = '0'; right = '1';
		} else {
			left = '1'; right = '0';
		}
		int left_matched, right_matched;
		left_matched = 0;
		right_matched = 0;
		for (int i=0; i<S.size(); ++i) {
			if (i%2 == 0) {
				left_matched += (S[i] == left) ? 1 : 0;
			} else {
				right_matched+= (S[i] == right) ? 1 : 0;
			}
		}
		total_matched = max(total_matched, left_matched + right_matched);
	}	
	cout << S.size() - total_matched << endl;
	return 0;
}

