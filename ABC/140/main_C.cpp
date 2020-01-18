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
    vector<int> B(N-1);
    for (int i=0; i<B.size(); ++i) {
        cin >> B[i];
    }
    vector<int> A(N);
    A[0] = B[0];
    // cout << A[0] << ", ";
    for (int i=1; i<B.size(); ++i) {
        A[i] = std::min(B[i-1], B[i]);
    }
    A[N-1] = B[N-2];
    // // debug
    // for (int i=0; i<A.size(); ++i) {
    //     cout << A[i] << ", ";
    // }
    // cout << endl;

    int ans = accumulate(A.begin(), A.end(), 0);
    cout << ans << endl;
	return 0;
}

