#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;
   typedef pair<ll, ll> Pii;
   typedef vector<ll> Vi;
   typedef vector<Vi> VVi;

   const double EPS = (1e-7);
   const ll INF =(1e13);
   const double PI = (acos(-1));
   const ll MOD = 998244353;

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

const ll MAX_N = 300, MAX_S = 300 * 300;
ll dp1[MAX_N + 1][MAX_S + 1] = {};
ll dp2[MAX_N + 1][MAX_S + 1] = {};
int main(){
  ll n; cin >> n;
  Vi a(n); REP(i, n) cin >> a[i];
  Vi s(n + 1, 0);
  REP(i, n){
    s[i + 1] = s[i] + a[i];
  }

  dp1[0][0] = 1;
  dp2[0][0] = 1;
  REP(i, n){
    REP(x, s[i + 1] + 1){
      if(x >= a[i]){
        dp1[i + 1][x] = (dp1[i][x - a[i]] + 2 * dp1[i][x]) % MOD;
        dp2[i + 1][x] = (dp2[i][x - a[i]] + dp2[i][x]) % MOD;
      }
      else{
        dp1[i + 1][x] = (2 * dp1[i][x]) % MOD;
        dp2[i + 1][x] = dp2[i][x];
      }
    }
  }
  ll total = pow(3, n, MOD);
  ll temp = 0;
  if(s[n] % 2 != 0){
    FOR(j, s[n] / 2 + 1, s[n] + 1){
      temp += dp1[n][j] * 3;
    }
  }
  else{
    FOR(j, s[n] / 2, s[n] + 1){
      temp += dp1[n][j] * 3;
    }
    temp -= dp2[n][s[n] / 2] * 3;
  }
  cout << residue(total -temp, MOD) << endl;

}
