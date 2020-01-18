#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using ll = long long;
using namespace std;

int main() {
    ll N, K;
    cin >> N >> K;

    ll k = K;
    int x = 0;
    while (N < k) {
        x++;
        k /= 2;
    }
    // x = 0 => K <= N
    // x = 1 => K/2 <= N < K
    // x = 2 => K/4 <= N < K/2
    // ...
    int xx = x;
    while (k > 0) {
        xx++;
        k /= 2;
    }
    int divider = 1;
    for (int i = 0; i<x; ++i) {
        divider *= 2;
    }
    k = K/divider;
    double ans = 0;
    for (int i = x; i<=xx; ++i) {
        if (i == 0) {
            ans += (N - K + 1 ) / N;
            continue;
        }
        double num = k%2 == 0 ? k/2 : (k+1) /2;
        if (i == x) {
            num = N - num;
        }
        divider *= 2;
        ans += num / N / divider;
        k /= 2;
    }
    cout << ans << endl;
    return 0;
}
