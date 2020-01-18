#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    string s_in;
    vector<string> s;
    for (int i=0;i<N;++i) {
        cin >> s_in;
        sort(s_in.begin(), s_in.end());
        s.push_back(s_in);
    }
    sort(s.begin(),s.end());
    ll ans = 0;
    ll cnt = 1;
    for (int i=1; i<s.size();++i) {
        if (s[i-1] == s[i]) {
            cnt++;
        } else {
            ans += (cnt * (cnt - 1)) / 2;
            cnt = 1;
        }
    }
    ans += (cnt * (cnt - 1)) / 2;
    cout << ans << endl;
    return 0;
}