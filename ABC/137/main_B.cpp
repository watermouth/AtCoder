#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    int K, X;
    cin >> K >> X;
    const int min_x = -1000000;
    const int max_x =  1000000;
    // 
    int bx = X - K + 1;
    int ex = X + K;
    for (int i=bx; i<ex; ++i) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}