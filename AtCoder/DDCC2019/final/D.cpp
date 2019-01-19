#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;
   typedef pair<ll, ll> Pii;
   typedef vector<ll> Vi;
   typedef vector<Vi> VVi;

   const double EPS = (1e-7);
   const ll INF =(1e13);
   const double PI = (acos(-1));
   const ll MOD = (1ll << 32);

   #define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
   #define REPR(i, n) for(ll i = n; i > -1; i--)
   #define FOR(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
   #define ALL(x) (x).begin(),(x).end()
   #define SORT(x) sort((x).begin(), (x).end())
   #define RSORT(x) sort((x).rbegin(), (x).rend()
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
   ll pow(ll a, ll b, ll m){if (b == 0) return 1; else if (b % 2 == 0) return (pow(a * a, b / 2, m) % m); else return (pow(a * a, b / 2) * a) % m;}

ll residue(ll a, ll m){return ((a % m) + m) % m;};

   ll dx[4]={1,0,-1,0};
   ll dy[4]={0,1,0,-1};
const ll MAX_Q = 1e5,MAX_S = 1e6;
const string DISCO = "DISCO";
string S;
ll N;
ll Q;
ll L[MAX_Q], R[MAX_Q];
ll dp[MAX_S + 1][6][6] = {};//dp[i + 1][a][b] = (S[0, i) にDISCO[a, b)が何通りあるか)
ll memo[6][6] = {};
ll query(ll l, ll r, ll a, ll b){
  //区間[l, r]にDISCO[a, b)がいくつあるか
  if (memo[a][b] >= 0) return memo[a][b];
  if (b == a) return 1;
  ll ans = dp[r][a][b];
  FOR(k, a + 1, b + 1){
    ans -= dp[l - 1][a][k] * query(l, r, k, b);
  }
  ans = residue(ans, MOD);
  memo[a][b] = ans;
  return ans;
}
int main(){
  cin >> S >> Q;
  REP(i, Q) cin >> L[i] >> R[i];
  REP(a, 5) dp[0][a][a] = 1;
  REP(i, S.size()){
    REP(a, 5){
      dp[i + 1][a][a] = 1;
      FOR(b, a + 1, 6){
        dp[i + 1][a][b] = dp[i][a][b] + dp[i][a][b - 1] * (S[i] == DISCO[b-1]);
        dp[i + 1][a][b] %= MOD;
        //printf("dp[%lld][%lld][%lld] = %lld\n", i+1, a, b, dp[i+1][a][b]);
      }
    }
  }
  REP(i, Q){
    REP(a, 6) REP(b, 6) memo[a][b] = -1;
    cout << query(L[i], R[i], 0, 5)<< endl;
  }
}
