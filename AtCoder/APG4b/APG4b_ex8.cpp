#include <bits/stdc++.h>
using namespace std;

int main() {
  int p;
  int price;
  int N;
  string text;

  cin >> p;
  // パターン1
  if (p == 1) {
    cin >> price;
  }

  // パターン2
  if (p == 2) {
    cin >> text >> price;
  }

  cin >> N;
  if (p == 2) {
      cout << text << "!" << endl;
  }
  cout << price * N << endl;
}
