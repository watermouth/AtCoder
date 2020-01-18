#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main() {
  ll X, Y, Z, K;
  cin >> X >> Y >> Z >> K;
  vector<ll> A(X,0), B(Y,0), C(Z,0);
  for (int i=0; i<X; ++i) cin >> A[i];
  for (int i=0; i<Y; ++i) cin >> B[i];
  for (int i=0; i<Z; ++i) cin >> C[i];

  // top 60
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());
  /*
  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());
  reverse(C.begin(), C.end());
  */

  ll AB_pivot = min(A[X-1], B[Y-1]);
  vector<ll>::iterator x_it, y_it;
  if (A[X-1] <= B[Y-1]) {
    x_it = lower_bound(B.begin(), B.end(), A[X-1]);
    y_it = B.end();
  } else {
    x_it = lower_bound(A.begin(), A.end(), B[Y-1]);
    y_it = A.end();
  }
  vector<ll> AB(min(3000, X*Y),0);
  int idx = 0;
  for (auto it = x_it; x_it != y_it; ++x_it) {
    AB[idx++] = AB_pivot * (*x_it);
    if (idx > AB.size()-1) break;
  }
  if (idx < AB.size()-1) {
    for (;idx < AB.size(); ++idx) {
      
    }
  }
  vector<ll> ABC(min(3000, X*Y*Z),0);
  ll ABC_pivot = min(AB[idx], C[Z-1]);
  if (AB[idx] <= C[Z-1]) {
    x_it = lower_bound(C.begin(), C.end(), AB[idx]);
    y_it = C.end();
  } else {
    x_it = lower_bound(AB.begin(), AB.begin() + idx, C[Z-1]);
    y_it = AB.begin() + idx;
  }
  for (auto it = x_it; x_it != y_it; ++x_it) {
    AB[idx++] = AB_pivot * (*x_it);
    if (idx > AB.size()-1) break;
  }
  vector<ll> ABC(min(3000, X*Y*Z),0);
  const ll ML = 100LL;
  const int MA = min(ML, X);
  const int MB = min(ML, Y);
  const int MC = min(ML, Z);
  vector<ll> V(MA*MB*MC, 0);
  int idx = 0;
  for (int i=0; i<MA; ++i) {
    for (int j=0; j<MB; ++j) {
      for (int k=0; k<MC; ++k) {
        V[idx++] = A[i] + B[j] + C[k];
      }
    }
  }
  sort(V.begin(), V.end());
  reverse(V.begin(), V.end());
  for (int i=0; i<K; ++i) {
    cout << V[i] << endl;
  }
  return 0;
}

