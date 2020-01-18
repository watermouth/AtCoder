#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
using ll = long long;
using namespace std;

int main() {
    ll N, K;
    cin >> N >> K;
    double ans = 0;
    for (int i=1; i<=N; ++i) {
        int x = i;
        double p = 1;
        while(x < K) {
            x*=2;
            p /= 2;
        }
        ans += (p/N);
    }
    cout << setprecision(15);
    cout << ans << endl;
    return 0;
}
