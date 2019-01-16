#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;
   typedef pair<ll, ll> Pii;

   const double EPS = (1e-7);
   const ll INF =(1e13);
   const double PI = (acos(-1));
   const ll MOD = ll(1e9) + 7;

   #define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
   #define REPR(i, n) for(ll i = n; i > -1; i--)
   #define FOR(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
   #define ALL(x) (x).begin(),(x).end()
   #define SORT(x) sort((x).begin(), (x).end())
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


   ll dx[4]={1,0,-1,0};
   ll dy[4]={0,1,0,-1};
const ll MAX_N = 21;
ll N;
ll a[MAX_N][MAX_N];
ll dp[MAX_N + 1][1ll << MAX_N] = {};

/* next combination */
ll next_combination(ll sub) {
    ll x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}

int main(){
  cin >> N;
  REP(i, N){
    REP(j, N){
      cin >> a[i][j];
    }
  }
  dp[0][0] = 1;
  REP(i, N){
    ll s = (1 << (i + 1)) - 1;
    for (; s < (1 << N); s = next_combination(s)){
      REP(k, N){
        if ((s >> k) && 1){
          dp[i + 1][s] += dp[i][s &  ~(1ll << k)] * a[i][k];
          dp[i + 1][s] %= MOD;
//          printf("i + 1 = %lld, s = %lld, k = %lld, s and not 1<<k = %lld\n", i + 1, s, k, (s & ~ (1ll << k)));
        }
      }
//    printf("dp[%lld][%lld] = %lld\n", i+1, s, dp[i + 1][s]);
    }
  }
  cout << (dp[N][(1ll << N) - 1] % MOD) << endl;
}
