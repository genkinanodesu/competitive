#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;
   typedef pair<ll, ll> Pii;
   typedef vector<ll> Vi;
   typedef vector<Vi> VVi;

   const double EPS = (1e-7);
   const ll INF =(1e13);
   const double PI = (acos(-1));
   const ll MOD = ll(1e9) + 7;

   #define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
   #define REPR(i, n) for(ll i = n; i > -1; i--)
   #define FOR(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
   #define ALL(x) (x).begin(),(x).end()
   #define SORT(x) sort((x).begin(), (x).end())
   #define RSORT(x) sort((x).rbegin(), (x).rend())
   #define REVERSE(x) reverse((x).begin(), (x).end())
   #define SZ(x) ((ll)(x).size())
   #define pb push_back
   #define mp make_pair

   //chmax(a, b): a>bならaをbで更新　更新したときにtrueを返す
   //chmin(a, b): a<bならaをbで更新　更新したときにtrueを返す
   template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
   template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

   #define dump(x) cerr<< #x << "= " << (x) << endl;

   ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
   ll pow(ll a, ll b){if (b == 0) return 1; else if (b % 2 == 0) return pow(a * a, b / 2); else return pow(a * a, b / 2) * a;}
   ll pow(ll a, ll b, ll m){if (b == 0) return 1; else if (a == 0) return 0; else if (b % 2 == 0) return (pow((a * a) % m, b / 2, m) % m); else return (pow((a * a) % m, b / 2, m) * a) % m;}
   ll residue(ll a, ll m){return ((a % m) + m) % m;};

   ll dx[4]={1,0,-1,0};
   ll dy[4]={0,1,0,-1};

int main(){
  ll n, X; cin >> n >> X;
  ll A = 0;
  Vi a(n); REP(i, n) {cin >> a[i]; A += a[i];}
  Vi x(n), z(n);
  ll Y = X / A, Z = X % A, Z_sum = 0;
  REP(i, n) x[i] = a[i] * Y;
  REP(i, n) {z[i] = (Z * a[i]) / A; Z_sum += z[i];}
  ll res = Z - Z_sum;
  cout << "a[i] : ";
  REP(i, n) cout << a[i] << ", ";
  cout << endl;
  cout << "z[i] : ";
  REP(i, n) cout << z[i] <<", ";
  cout << endl;

  vector<vector<double>> dp(n + 1, vector<double>(res + 1, (double)(1e10)));
  dp[0][0] = 0.0;
  REP(i, n){
    dp[i + 1][0] = dp[i][0] + abs((double)z[i] / (double)a[i] - (double)Z / (double)A);
    REP(j, res){
      dp[i + 1][j + 1] = min(dp[i][j] + abs((double)(z[i] + 1) / (double)a[i] - (double)Z / (double)A),
                              dp[i][j + 1] + abs((double)z[i] / (double)a[i] - (double)Z / (double)A));
    }
  }
  // REP(i, n) {
  //   REP(j, res + 1){
  //     printf("dp[%lld][%lld] = %.8f ", i + 1, j, dp[i + 1][j]);
  //   }
  //   printf("\n");
  // }
  ll j = res;
  for(ll i = n - 1; i >= 0; i--){
    x[i] += z[i];
    if(j == 0) continue;
    if(dp[i + 1][j] == dp[i][j - 1] + abs((double)(z[i] + 1) / (double)a[i] - (double)Z / (double)A)){
      x[i]++;
      j--;
    }
  }
  REP(i, n) cout << x[i] << endl;
}
