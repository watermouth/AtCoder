#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    // vector<int> x(5,0);
    // for (int i=0;i<5;++i) {
    //     cin >> x[i];
    // }
    int A,B;
    cin >> A >> B;
    cout << max(A+B, max(A-B, A*B)) << endl;
    return 0;
}