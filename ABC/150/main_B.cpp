#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

////////////////////////// templates

template<class U>
void PRINT(std::vector<U> &x) {
    for (int i=0;i<x.size();++i) {
        cout << x[i];
    }
}

template<class U>
void PRINTLN(std::vector<U> &x) {
    PRINT<U>(x);
    cout << endl;
}

////////////////////////// functions

////////////////////////// main

int main() {
    ll N;
    string S;
    cin >> N >> S;
    int ans = 0;
    for (int i=0;i<N-2;++i) {
        if(S[i]=='A' && S[i+1]=='B' && S[i+2]=='C') ans++;
    }
    cout << ans << endl;
    return 0;
}