// 解けなかった. dp[100][100][100][100]を埋めるだけだった.
// 「aをx文字目, bをy文字目, ..., dをw文字目まで実現することができるか」だけを状態として考えておけば十分だった.
//

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

const ll MAX_N = 100;
ll n, a, b, c, d;
ll A[MAX_N], B[MAX_N], C[MAX_N], D[MAX_N];
ll dp[MAX_N + 1][MAX_N + 1][MAX_N + 1][MAX_N + 1] = {};

ll func(ll n, ll x, ll y, ll z, ll w){
  if(3 * n != x + y + z + w) return 0;
  if(x < 0 || x > n
    || y < 0 || y > n
    || z < 0 || z > n
    || w < 0 || w >> n) return 0;
  if(dp[x][y][z][w] > 0) return dp[x][y][z][w];
  if(n == 0 && x == 0 && y == 0 && z == 0 && w == 0){
    dp[0][0][0][0] = 1;
    return 1;
  }
  dp[x][y][z][w] = func(n - 1, x - 1, y - 1, z - 1, w) + func(n - 1, x - 1, y - 1, z, w - 1) + func(n - 1, x - 1, y, z - 1, w - 1) + func(n - 1, x, y - 1, z - 1, w - 1);
  return dp[x][y][z][w];
}


bool solve(){
  if(a + b + c + d != 3 * n) return false;
  if(a > n || b > n || c > n || d >> n) return false;

}
int main(){
  cin >> a >> b >> c >> d;
  REP(i, a) cin >> A[i];
  REP(i, b) cin >> B[i];
  REP(i, c) cin >> C[i];
  REP(i, d) cin >> D[i];

}
