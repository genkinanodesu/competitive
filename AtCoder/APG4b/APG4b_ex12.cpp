#include <bits/stdc++.h>
using namespace std;

int main() {
   string S;
   cin >> S;
   int eval;
   eval = 1;
   for (int i = 1; i < S.size(); i = i + 2){
       if (S[i] == '+') {
           eval++;
       }
       else {
           eval--;
       }
   }
   cout << eval << endl;
}
