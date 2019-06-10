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

const ll MAX_N = 120 ;
ll n, a, b, c, d;
ll score[4][MAX_N];
bool dp[MAX_N + 1][MAX_N + 1][MAX_N + 1][MAX_N + 1] = {};
bool check[MAX_N + 1][MAX_N + 1][MAX_N + 1][MAX_N + 1] = {};

bool solve(ll n, Vi x){
  if(3 * n != x[0] + x[1] + x[2] + x[3]) return false;
  REP(i, 4){
    if(x[i] < 0 || x[i] > n) return false;
  }
  if(check[x[0]][x[1]][x[2]][x[3]]) return dp[x[0]][x[1]][x[2]][x[3]];
  ll p[4] = {score[0][x[0]], score[1][x[1]], score[2][x[2]], score[3][x[3]]};
  REP(i, 4){
    FOR(j, i + 1, 4){
      FOR(k, j + 1, 4){
        Vi y = x;
        y[i]--; y[j]--; y[k]--;
        if(p[i] != p[j] && p[i] != p[k] && p[j] != p[k]) dp[x[0]][x[1]][x[2]][x[3]] += solve(n - 1, y);
      }
    }
  }
  check[x[0]][x[1]][x[2]][x[3]] = true;
  return dp[x[0]][x[1]][x[2]][x[3]];
}
Vi worst(ll n, Vi x){
  if(n == 0) return {};
  if(!solve(n, x)) return {};
  REP(i, 4){
    FOR(j, i + 1, 4){
      FOR(k, j + 1, 4){
        Vi y = x;
        y[i]--; y[j]--; y[k]--;
        if(solve(n - 1, y)){
          Vi tmp = worst(n - 1, y);
          tmp.pb((0 + 1 + 2 + 3) - i - j - k + 1);
          return tmp;
        }
      }
    }
  }
  return {};
}
int main(){
  cin >> n >> a >> b >> c >> d;
  score[0][0] = -1, score[1][0] = -1, score[2][0] = -1, score[3][0] = -1;
  REP(i, a) cin >> score[0][i + 1];
  REP(i, b) cin >> score[1][i + 1];
  REP(i, c) cin >> score[2][i + 1];
  REP(i, d) cin >> score[3][i + 1];
  dp[0][0][0][0] = true;
  check[0][0][0][0] = true;
  Vi x = {a, b, c, d};
 // cout << solve(n, x) << endl;
 //  REP(i, a + 1){
 //    REP(j, b + 1){
 //      REP(k, c + 1){
 //        REP(l, d + 1){
 //          printf("dp[%d][%d][%d][%d] = %d\n", i, j, k, l, dp[i][j][k][l]);
 //        }
 //      }
 //    }
 //  }
  if(!solve(n, x)) {cout << "No" << endl; return 0;}
  cout << "Yes" << endl;
  Vi w = worst(n, x);
  REP(i, n) cout << w[i] << endl;
}
