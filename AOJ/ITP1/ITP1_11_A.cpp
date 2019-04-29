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
    vector<int> new_side(6);
    for(int i = 0; i < 6; i++) new_side[i] = side[t[i]];
    side = new_side;
  }
};

int main(){
  vector<int> _side(6);
  for(int i = 0; i < 6; i++) cin >> _side[i];
  Dice d(_side);
  string s; cin >> s;
  for(int i = 0; i < s.size(); i++){
    d.rotate(s[i]);
  }
  cout << d.side[0] << endl;
}
