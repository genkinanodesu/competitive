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
};

int main(){
  vector<int> _side(6);
  for(int i = 0; i < 6; i++) cin >> _side[i];
  Dice d(_side);
  int q; cin >> q;
  for(int i = 0; i < q; i++){
    int top, front; cin >> top >> front;
    for(int k = 0; k < 4; k++){
      if(d.side[0] == top) break;
      d.rotate('N');
    }
    for(int k = 0; k < 4; k++){
      if(d.side[0] == top) break;
      d.rotate('E');
    }
    for(int k = 0; k < 4; k++){
      if(d.side[1] == front) break;
      d.rotate('L');
    }
    cout << d.side[2] << endl;
  }
}
