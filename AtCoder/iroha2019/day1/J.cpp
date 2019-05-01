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
const ll MAX = (1e5 + 2) / 2;
ll factorial[MAX + 1] = {};
ll factorial_inv[MAX + 1] = {};

void preproc(){
  factorial[0] = 1;
  factorial_inv[0] = 1;
  REP(i, MAX){
    factorial[i + 1] = (factorial[i] * (i + 1)) % MOD;
    factorial_inv[i + 1] = (factorial_inv[i] * pow(i + 1, MOD - 2, MOD)) % MOD;
  }
}

ll binom(ll n, ll m){
  return ((factorial[n] * factorial_inv[m]) % MOD * factorial_inv[n - m]) % MOD;
}
ll kaibun(ll n, ll x){
  //全部でn文字, 1がx文字登場する回文の個数.
  if(n % 2 == 0 && x % 2 == 1) return 0;
  return binom(n / 2, x / 2);
}
ll func(ll n, ll k){
  //n, kが与えられたときの答え
  ll x = -1, y = -1;
  for(ll i = 0; i * i <= 2 * k; i++){
    if(i * (n - i) == 2 * k){
      x = i; y = n - i;
      break;
    }
  }
  //解無し
  if(x == -1 && y == -1) return 0;
  if(x == y) return kaibun(n, x);
  else return (kaibun(n, x) * 2 ) % MOD;
}
int main(){
  preproc();
  ll q; cin >> q;
  Vi ans(q);
  REP(i, q){
    ll n, k; cin >> n >> k;
    ans[i] = func(n, k);
  }

  REP(i, q) cout << ans[i] << endl;
}
