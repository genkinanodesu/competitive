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

const ll MAX_H = 185, MAX_W = 185;
ll h, w;
VVi grid, grid_cum;
vector<vector<vector<vector<ll>>>> dp;
// bool grid[MAX_H][MAX_W];
// ll grid_cum[MAX_H + 1][MAX_W + 1] = {};
// ll dp[MAX_H + 1][MAX_H + 1][MAX_W + 1][MAX_W + 1];

ll complexitiy(ll x1, ll x2, ll y1, ll y2){
  if(x1 >= x2 || y1 >= y2) return 0;
  if(dp[x1][x2][y1][y2] >= 0) return dp[x1][x2][y1][y2];
  ll cnt = grid_cum[x2][y2] - grid_cum[x1][y2] - grid_cum[x2][y1] + grid_cum[x1][y1];
  if(cnt == 0 || cnt == (x2 - x1) * (y2 - y1)){
    dp[x1][x2][y1][y2] = 0; return 0;
  }
  ll res = INF;
  for(ll x = x1 + 1; x < x2; x++){
    chmin(res, max(complexitiy(x1, x, y1, y2), complexitiy(x, x2, y1, y2)) + 1);
  }
  for(ll y = y1 + 1; y < y2; y++){
    chmin(res, max(complexitiy(x1, x2, y1, y), complexitiy(x1, x2, y, y2)) + 1);
  }
  dp[x1][x2][y1][y2] = res;
  return res;
}
int main(){
  cin >> h >> w;
  grid.assign(h, Vi(w));
  grid_cum.assign(h + 1, Vi(w + 1, 0));
  dp.assign(h + 1, vector<VVi>(h + 1, VVi(w + 1, Vi(w + 1, -1))));
  REP(i, h) REP(j, w){
    char c; cin >> c;
    grid[i][j] = ((c == '#') ? true : false);
  }
  REP(i, h) REP(j, w) grid_cum[i + 1][j + 1] = grid[i][j] + grid_cum[i + 1][j] + grid_cum[i][j + 1] - grid_cum[i][j];
  REP(i1, h + 1) REP(i2, h + 1) REP(j1, w + 1) REP(j2, w + 1) dp[i1][i2][j1][j2] = -1;

  cout << complexitiy(0, h, 0, w) << endl;
}
