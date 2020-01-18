#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
using ll = long long;

int main() {
	ll N, K;
	cin >> N >> K;
    string S;
    cin >> S;
    if (N-1 <= K) {
        cout << N-1 << endl;
        return 0;
    }
    // 最初のスコア + 改善可能スコア
    int score = 0;
    int cluster_count = 1;
    vector<int> X(N,0);
    for (int i=1; i<S.size(); ++i) {
        if (S[i] == S[i-1]) {
            score++;
        } else {
            cluster_count++;
        }
    }
    for (int i=0; i<K; ++i) {
        if (cluster_count == 1) {
            break;
        }
        if (cluster_count > 2) {
            score+=2;
            cluster_count -= 2;
        } else {
            score++;
            cluster_count--;
        }
    }
    cout << score << endl;
	return 0;
}
