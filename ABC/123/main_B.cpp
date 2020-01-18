#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
  vector<int> X(5,0);
  vector<int> Y(5,0);
  int min_mod = 10;
  int min_index = 0;
  for (int i=0; i<5; ++i) {
    cin >> X[i];
    int temp = X[i] % 10;
    if (temp == 0) {
      Y[i] = X[i];
    } else {
      Y[i] = X[i] - temp + 10;
      if (temp < min_mod) {
        min_index = i;
        min_mod = temp;
      }
    }
  }
  int ans = 0;
  for (int i=0; i<5; ++i) {
    ans += (i == min_index) ? X[i] : Y[i];
  }
  cout << ans << endl;
  return 0;
}

