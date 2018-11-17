#include <bits/stdc++.h>
using namespace std;

/*
templates for competitive programming
type long long -> type ll 
define constants : EPS, INF, MOD, PI
define macros : REP, FOR, ALL, SORT, REVERSE
define number theory functions: qp(a, b), qp(a, b, mo), gcd(a, b)
define dx, dy
*/
   typedef long long ll;

   const double EPS = (1e-7);
   const int INF =(1e9);
   const double PI = (acos(-1));
   const ll MOD = (ll(1e9) + 7);

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


int main() {
   cin.tie(0);
   ios::sync_with_stdio(false);
   //input
   ll n, m; cin >> n >> m;
   vector<ll> f(n);
   REP(i, n){
       cin >> f[i];
   }
   ll a[n]; // a[i] = fi, fi+1, ..., fjに重複が生まれるような最小のj
   ll temp = 0;
   set<ll> s;
   REP(i, n){
       if (i > temp) temp = i;
       while (temp < n && s.count(f[temp]) == 0){
           s.insert(f[temp]);
           temp++;
       }
       a[i] = temp;
       s.erase(f[i]);
   }
   // dp[i] = f0, f1, ..., fi-1 までを摂取済みのときの残りの食べ方
   // dp[n] = 1
   // 答はdp[0]
   // dp[i] = sum (fi, fi+1, ..., fjに重複がないようなj) dp[j]
   // 各jに対し, fi, fi+1, ..., fjに重複がないような最大のjを求めておく

   ll dp[n + 1];
   dp[n] = 1;
   ll dp_cum[n + 2]; // dp_cum[i] = dp[i] + ... + dp[n]
   dp_cum[n + 1] = 0;
   dp_cum[n] = 1;

   for (int i = n - 1; i > -1; i--){
       dp[i] = (dp_cum[i + 1] - dp_cum[a[i] + 1]) % MOD;
       dp_cum[i] = dp_cum[i + 1] + dp[i];
   }
   ll ans = dp[0] % MOD;
   cout << ans << endl;
}