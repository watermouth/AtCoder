#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<int> x(5,0);
  for (int i=0;i<5;++i) {
    cin >> x[i];
  }
  string s = "Yay!";
  int k;
  cin >> k;
  for (int i=0; i<5; ++i) {
    for (int j=i+1; j<5; ++j) {
      if (x[j] - x[i] > k) {
        s = ":(";
      }
    }
  }
  cout << s << endl;
  return 0;
}


