#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;
using ll = long long;

int main() {
	ll N;
	cin >> N;
    vector<int> A(N), B(N), C(N-1);
    for (int i=0;i<N;++i) {
        cin >> A[i];
        A[i]--;
    }
    for (int i=0;i<N;++i) {
        cin >> B[i];
    }
    for (int i=0;i<N-1;++i) {
        cin >> C[i];
    }
    int ans = accumulate(B.begin(), B.end(), 0);
    for (int i=0; i<N-1; ++i) {
        if (A[i+1] == A[i]+1) {
            ans += C[A[i]];
        }
    }
    cout << ans << endl;
	return 0;
}

