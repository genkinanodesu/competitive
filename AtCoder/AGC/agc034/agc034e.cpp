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
const ll MAX_N = 2000;
ll d[MAX_N][MAX_N] = {};
ll n;
int main(){
  cin >> n;
  string s; cin >> s;
  REP(i, n) REP(j, n) {
    if(i != j) d[i][j] = INF;
  }
  REP(i, n - 1){
    ll a, b; cin >> a >> b; a--; b--;
    d[a][b] = 1; d[b][a] = 1;
  }
  REP(i, n) REP(j, n) REP(k, n) chmin(d[i][j], d[i][k] + d[k][j]);

  REP(i, n) REP(j, n){
    printf("d[%lld][%lld] = %lld\n", i, j, d[i][j]);
  }
  ll tmp = 0;
  REP(i, n) FOR(j, i + 1, n){
    if(s[i] == '1' && s[j] == '1') tmp += d[i][j];
  }
  if(tmp % 2 == 1){
    cout << -1 << endl;
    return 0;
  }
  ll ans = INF;
  REP(i, n){
    ll x = 0;
    REP(j, n){
      if(s[j] == '1') x += d[i][j];
    }
    chmin(ans, x / 2);
  }
  cout << ans << endl;
}
