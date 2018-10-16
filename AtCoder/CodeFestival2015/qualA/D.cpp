#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;

   const double EPS = (1e-7);
   const int INF =(1e9);
   const double PI = (acos(-1));
   const int MOD = (int(1e9) + 7);

   #define REP(i, n) for(int i = 0; i < (int)(n); i++)
   #define FOR(i, a, b) for (int i = (a); i < (b); i++)
   #define ALL(x) (x).begin(),(x).end()
   #define SORT(x) sort((x).begin(), (x).end())
   #define REVERSE(x) reverse((x).begin(), (x).end())
   #define SZ(x) ((int)(x).size())


   #define dump(x) cerr<< #x << "= " << (x) << endl;

   int gcd(int a,int b){return b?gcd(b,a%b):a;};

   int dx[4]={1,0,-1,0};
   int dy[4]={0,1,0,-1};

ll n, m;
vector<ll> x;

bool C(ll k){
    // 点検をk分で終了させることができるかどうか
    ll temp = 0;
    // temp台目まで点検が終わっている
    REP(i, m){
        if (x[i] - temp - 1 > k) {
            return false;
        }
        else if (temp >= x[i]){
            temp = x[i] + k;
        }
        else {
            temp = max(k + 2 * temp + 2 - x[i], (k + temp + x[i] + 1) / 2 );
        }
    }
    if (temp >= n) return true;
    else return false;
}
int main() {
   cin.tie(0);
   ios::sync_with_stdio(false);
   cin >> n >> m;
   REP(i, m){
       ll xi;
       cin >> xi;
       x.push_back(xi);
   }
   ll lb = -1;
   ll ub = 2 * n;
   while (ub - lb > 1){
       ll mid = (lb + ub) / 2;
       C(mid) ? ub = mid : lb = mid;
   }
   cout << ub << endl;
}