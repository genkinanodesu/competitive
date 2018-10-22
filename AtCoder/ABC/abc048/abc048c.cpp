#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;

   const double EPS = (1e-7);
   const int INF =(1e9);
   const double PI = (acos(-1));
   const int MOD = int(1e9) + 7;

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
   ll n, x; cin >> n >> x;
   vector<ll> a(n);
   REP(i, n) cin >> a[i];

   ll ans = 0;
   REP(i, n - 1){
       if (a[i] + a[i + 1] > x){
           ll s = min(a[i], x), t = min(a[i + 1], x - s);
           ans += a[i] - s + a[i + 1] - t;
           a[i] = s;
           a[i + 1] = t;
       }
   }
   cout << ans << endl;
}