#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using ll = long long;
using namespace std;

int main() {
    string S;
    cin >> S;

    int x = stoi(S);
    string ans;
    int up = x / 100;
    int down = x % 100;
    bool up_in = up <= 12 && up >= 1;
    bool down_in = down <= 12 && down >= 1;

    if (up_in && down_in) {
        ans = "AMBIGUOUS";
    } else if (up_in && !down_in) {
        ans = "MMYY";
    } else if (!up_in && down_in) {
        ans = "YYMM";
    } else if (!up_in && !down_in) {
        ans = "NA";
    }
    cout << ans << endl;
    return 0;
}
