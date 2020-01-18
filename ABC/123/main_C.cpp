#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;
  const size_t M = 5;
  vector<ll> X(M,0);
  for (int i=0; i<M; ++i) {
    cin >> X[i];
  }
  // find bottle neck
  ll min_size = *min_element(X.begin(), X.end());
  ll ans = (M-1) + (N / min_size) + ((N % min_size == 0) ? 0 : 1);
  cout << ans << endl;
  return 0;
}

