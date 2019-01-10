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
const ll MAX_N = 1e5, MAX_M = 1e5;
ll N, M;
ll x[MAX_N], y[MAX_N];
vector<ll> vin[MAX_N] = {};
vector<ll> vout[MAX_N] = {};
ll dp[MAX_N];

ll longest_path(ll x){
  //xを始点とするlongest path
  if (dp[x] >= 0) return dp[x];
  else if (vout[x].empty()) {
    //x
    dp[x] = 0;
    return 0;
  }
  else{
    ll ans = -1;
    for(auto i = vout[x].begin(); i != vout[x].end(); i++){
      chmax(ans, longest_path(*i) + 1);
    }
    dp[x] = ans;
    return ans;
  }
}

int main(){
  cin >> N >> M;
  REP(i, M){
    ll xi, yi;
    cin >> xi >> yi;
    x[i] = xi - 1; y[i] = yi - 1;
    //有向辺xi-1 -> yi-1
    vout[xi - 1].pb(yi - 1);
    vin[yi - 1].pb(xi - 1);
  }
  REP(i, N){
    dp[i] = -1;
  }
  ll ans = -1;
  REP(i, N){
//    dump(longest_path(i))
//    dump(vout[i].size())
//    dump(vin[i].size())
    chmax(ans, longest_path(i));
  }
  cout << ans << endl;
}
