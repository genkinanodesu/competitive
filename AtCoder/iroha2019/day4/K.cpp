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

const ll MAX_N = 2e5;
ll factorial[MAX_N + 1];
ll factorial_inv[MAX_N + 1];

void maeshori(ll n){
  factorial[0] = 1, factorial_inv[0] = 1;
  REP(i, n){
    factorial[i + 1] = (factorial[i] * (i + 1)) % MOD;
    factorial_inv[i + 1] = (factorial_inv[i] * pow(i + 1, MOD - 2, MOD)) % MOD;
  }
}

class BIT{
   //1-index, A1, A2, ..., A_Mの更新および累積和をO(logM)で求める.
   public:
       vector<ll> bit;
       ll M;

   BIT(ll M):
       //宣言と初期化
       bit(vector<ll>(M+1, 0)), M(M) {}

   ll sum(ll i) {
       if (!i) return 0;
       return bit[i] + sum(i-(i&-i));
   }

   void add(ll i, ll x) {
       if (i > M) return;
       bit[i] += x;
       add(i+(i&-i), x);
   }
};
int main(){
  ll n;
  cin >> n;
  Vi p(n);
  REP(i, n) cin >> p[i];

  ll ans = 1;
  REP(i, n - 1){
    ans *= i + 1; ans %= MOD;
  }
  BIT b(n);
  REP(i, n){
    b.add(p[i], 1);
    // cout << b.sum(p[i]) << endl;
    ans *= pow(b.sum(p[i]), MOD - 2, MOD); ans %= MOD;
    cout << b.sum(p[i]) << endl;
  }
  cout << ans << endl;
}
