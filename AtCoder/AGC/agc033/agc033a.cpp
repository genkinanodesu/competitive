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

ll h, w;
bool in_grid(ll x, ll y){
  return (0 <= x && x < h && 0 <= y && y < w);
}
int main(){
  cin >> h >> w;
  VVi grid(h, Vi(w, INF));
  REP(i, h) REP(j, w){
    char c; cin >> c;
    if(c == '#') grid[i][j] = 0;
  }
  queue<Pii> q;
  REP(i, h) REP(j, w) if(!grid[i][j]) q.push(mp(i, j));
  while(!q.empty()){
    Pii p = q.front(); q.pop();
    ll x = p.first, y = p.second;
    REP(k, 4){
      if(in_grid(x + dx[k], y + dy[k])
      && chmin(grid[x + dx[k]][y + dy[k]], grid[x][y] + 1)){
        q.push(mp(x + dx[k], y + dy[k]));
      }
    }
  }
  ll ans = 0;
  REP(i, h) REP(j, w) chmax(ans, grid[i][j]);
  // REP(i, h){
  //   REP(j, w){
  //     printf("%lld\t", grid[i][j]);
  //   }
  //   printf("\n");
  // }
  cout << ans << endl;

}
