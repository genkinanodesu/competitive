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
const ll MAX_N = 1e5;
ll N;
vector<ll> G[MAX_N] = {}; //頂点iに隣接する頂点
//dp1[i] = 頂点iを黒く塗った時に部分木を塗る方法, dp2[i] = 頂点iを白く塗った時に部分木を塗る方法
ll dp1[MAX_N] = {}, dp2[MAX_N] = {}, is_reached[MAX_N] = {};

void dfs(ll v){
  if (is_reached[v] == 0){
    is_reached[v] = 1;
    dp1[v] = 1; dp2[v] = 1;
    for (auto u = G[v].begin(); u != G[v].end();u++){
      if (is_reached[*u] == 0){
        dfs(*u);
        dp1[v] *= dp2[*u];
        dp1[v] %= MOD;
        dp2[v] *= (dp1[*u] + dp2[*u]);
        dp2[v] %= MOD;
      }
    }
//    printf("dp1[%lld] = %lld, dp2[%lld] = %lld\n", v, dp1[v], v, dp2[v]);
  }
}

int main(){
  cin >> N;
  REP(i, N - 1){
    ll xi, yi;
    cin >> xi >> yi;
    G[xi - 1].pb(yi - 1);
    G[yi - 1].pb(xi - 1);
  }
  dfs(0);
  cout << (dp1[0] + dp2[0]) % MOD << endl;
}
