#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct S {
    int A;
    int B;
};

struct Comp {
    bool operator()(const S &i, const S &j) {
        if (i.B == j.B) {
            return (i.A > j.A);
        }
        return (i.B > j.B);
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<S> data(N);
    for (int i=0;i<N;++i) {
        cin >> data[i].A >> data[i].B;
    }
    // Aは日数. Bが報酬
    // Aを受ける順番も重要
    // Bの和を最大化したい
    // 制約付き最大化問題
    // 受ける順番の関数h: i -> h(i) について, 
    // max \sum _i B[h(i)] I{(A[h(i)] + i) <= M} を求める問題. Iはindicator function
    sort(data.begin(), data.end(), Comp());
    ll ans = 0;
    vector<int> schedule(N,0);// i番目が1ならその日のバイトが決まっている
    for (int i=0; i<N; ++i) {
        // 期限
        int begin_day = min(M - data[i].A, N-1);
        // cout << begin_day << endl;
        if (begin_day < 0) {
            continue;
        }
        if (schedule[begin_day] == 0) {
            schedule[begin_day]=1;
            ans += data[i].B;
        } else {
            while(begin_day > 0) {
                begin_day--;
                if (schedule[begin_day] == 0) {
                    schedule[begin_day] = 1;
                    ans += data[i].B;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}