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
int dfs(int M, const vector<int> X) {
    int N = X.size()-1;
    if (M==N) {
        return 1;
    }
    int temp = 1;
    for (int i=1;i<=(N-M);++i) {
        temp *= i;
    }
    int ans = 0;
    for (int i=M;i<=N;++i) {
        if(X[i] < X[M]) ans += temp;
    }
    ans += dfs(M+1, X);
    return ans;
}

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
    int a = dfs(1, P);
    int b = dfs(1, Q);
    // cout << a << ", " << b << endl;
    cout << abs(a-b) << endl;
    return 0;
}