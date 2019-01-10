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
const ll MAX_N = 3e3;
ll N;
ll a[MAX_N] = {};
ll dp[MAX_N + 1][MAX_N + 1];

ll score(ll i, ll j){
  //ai, ai+1, ..., aj1が初期設定の時の得点
  if (i > j) return -INF;
  else if (dp[i][j] > -INF) return dp[i][j];
  else{
    if (i == j) dp[i][j] = a[i];
    else{
      dp[i][j] = max( a[i] - score(i + 1, j) , a[j] - score(i, j - 1));
    }
    return dp[i][j];
  }
}
int main(){
  cin >> N;
  REP(i, N){
    cin >> a[i];
  }
  REP(i, N + 1){
    REP(j, N + 1){
      dp[i][j] = -INF;
    }
  }
  cout << score(0, N - 1) << endl;
}
