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

const ll MAX_N = 365;
ll dp[MAX_N + 1][MAX_N + 1] = {};
int main(){
  ll n, m, k; cin >> n >> m >> k;
  Vi a(n); REP(i, n) cin >> a[i];
  REP(i, n + 1){
    REP(j, m + 1){
      dp[i][j] = -INF;
    }
  }
  FOR(i, n - k + 1, n + 1) dp[i][0] = 0;
  for(ll x = 1; x <= m; x++){
    for(ll i = n; i >= 0; i--){
      for(ll j = 1; i + j <= n && j <= k; j++){
        chmax(dp[i][x], dp[i + j][x - 1] + a[i + j - 1]);
      }
    }
  }
  /*
  REP(i, n + 1){
    REP(x, m + 1){
      printf("dp[%lld][%lld] = %lld\n", i, x, dp[i][x]);
    }
  }
  */
  cout << ((dp[0][m] >= 0) ? dp[0][m] : -1) << endl;
}