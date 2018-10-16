#include <bits/stdc++.h>
using namespace std;

    typedef long long ll;
   ll power(ll a, ll b){
       if (b == 0) return 1;
       else if (b % 2 == 0) return power(a * a, b / 2);
       else return a * power(a, b - 1);
   }

int main(){
    for (int i = 0; i < 50; i++){
        cout << pow(2, i) << endl;
    }
    for (int i = 0; i < 50; i++){
        cout << power(2, i) << endl;
    }
}