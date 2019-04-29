#include <bits/stdc++.h>
using namespace std;

class Dice{
public:
  vector<int> side;

  Dice(vector<int> _side){
    side = _side;
  }
  void rotate(char c){
    vector<int> t;
    if(c == 'N') t = {1, 5, 2, 3, 0, 4};
    else if (c == 'S') t = {4, 0, 2, 3, 5, 1};
    else if (c == 'E') t = {3, 1, 0, 5, 4, 2};
    else if (c == 'W') t = {2, 1, 5, 0, 4, 3};
    else if (c == 'L') t = {0, 3, 1, 4, 2, 5};
    else if (c == 'R') t = {0, 2, 4, 1, 3, 5};
    vector<int> new_side(6);
    for(int i = 0; i < 6; i++) new_side[i] = side[t[i]];
    side = new_side;
  }
  void rotate(char c, int n){
    for(int i = 0; i < n; i++) rotate(c);
  }
};

int main(){
  vector<int> _side(6);
  for(int i = 0; i < 6; i++) cin >> _side[i];
  Dice d1(_side);
  for(int i = 0; i < 6; i++) cin >> _side[i];
  Dice d2(_side);
  Dice d1_cp = d1;
  for(int x = 0; x < 4; x++){
    for(int y = 0; y < 4; y++){
      for(int z = 0; z < 4; z++){
        d1_cp.rotate('N', x);
        d1_cp.rotate('E', y);
        d1_cp.rotate('L', z);
        if(d1_cp.side == d2.side){
          cout << "Yes" << endl;
          return 0;
        }
        d1_cp = d1;
      }
    }
  }
  cout << "No" << endl;
}
