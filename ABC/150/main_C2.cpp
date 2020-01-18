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
    vector<int> P(N+1,-1), Q(N+1,-1);
    for (int i=1;i<=N;++i){
        cin >> P[i];
    }
    for (int i=1;i<=N;++i){
        cin >> Q[i];
    }
    vector<int> R(N+1,-1);
    for (int i=1;i<=N;++i) {
        R[i] = i;
    }
    
    int c=1;
    int a = 0, b = 0;
    do {
        if (P == R) a = c;
        if (Q == R) b = c;
        ++c;
    } while(next_permutation(R.begin()+1, R.end()));

    cout << abs(a-b) << endl;
    return 0;
}