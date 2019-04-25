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

//拡張Euclidの互除法
//ap + bq = gcd(a, b) なる(p, q)を求め, d = gcd(a, b)をリターン
ll extGcd(ll a, ll b, ll &p, ll &q){
    if (b == 0) {
        p = 1; q = 0; return a;
    }
    ll d = extGcd(b, a % b, q, p);
    q -= a / b * p;
    return d;
}

ll inverse(ll x){
   //1/x mod MODを返す
   return pow(x, MOD-2, MOD);
}
int main(){
   ll b, w; cin >> b >> w;

   //nC(b-1), nC(w-1)をリストアップしておく
   Vi comb_b(b+w+2, 0), comb_w(b+w+2, 0);
   REP(i, b + w + 2){
      if(i == b - 1) comb_b[i] = 1;
      if(i > b - 1) comb_b[i] = residue(comb_b[i-1] * i * inverse(i - b + 1), MOD);
      if(i == w - 1) comb_w[i] = 1;
      if(i > w - 1) comb_w[i] = residue(comb_w[i-1] * i * inverse(i - w + 1), MOD);
   }

   Vi P(b+w+1, 0), Q(b+w+1, 0), X(b+w+1, 0);
   REP(i, b + w){
      (i + 1 < b) ? P[i + 1] = 0 : P[i + 1] = (2 * P[i] + comb_b[i]) % MOD;
      (i + 1 < w) ? Q[i + 1] = 0 : Q[i + 1] = (2 * Q[i] + comb_w[i]) % MOD;
      X[i + 1] = residue(pow(2, i, MOD) + Q[i] - P[i], MOD);
   }
   REP(i, b + w){
      cout << residue(X[i + 1] * pow( (1 + MOD) / 2 , i + 1, MOD), MOD) << endl;
    }
}
