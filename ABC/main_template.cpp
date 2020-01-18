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
    cin >> N;
    vector<int> A(N,0);
    for (ll i=0;i<N;++i) {
        cin >> A[i];
    }
    PRINTLN<int>(A);
    return 0;
}