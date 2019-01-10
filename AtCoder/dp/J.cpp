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
const ll MAX_N = 300;
ll N;
ll a[MAX_N];
ll x = 0, y = 0, z = 0;
double dp[3 * MAX_N + 1][ (3 * MAX_N / 2) + 2][MAX_N + 1] = {};

double sushi(ll x, ll y, ll z){
  //1-kan * x, 2-kan * y, 3-kan * z
  if (x == 0 && y ==0 && z == 0) return 0;
  else if (x < 0 || y < 0 || z < 0 || (x + 2 * y + 3 * z > x + 2 * y + 3 * z)) return 0;
  else if (dp[x][y][z] >= 0) return dp[x][y][z];
  else{
    double ans = (x * sushi(x-1,y,z) + y * sushi(x+1,y-1,z) + z * sushi(x,y+1,z-1) + N) / (double)(x+y+z);
    dp[x][y][z] = ans;
    return ans;
  }
}
int main(){
  cin >> N;
  REP(i, N){
    cin >> a[i];
    if (a[i] == 1) x++;
    if (a[i] == 2) y++;
    if (a[i] == 3) z++;
  }

  REP(i, 3 * N + 1){
    REP(j, (3 * N / 2) + 2){
      REP(k, N + 1){
        dp[i][j][k]= -1.0;
      }
    }
  }
  /*
  REP(i, 3 * N + 1){
    REP(j, 2 * N + 1){
      REP(k, N + 1){
        if (i + 2 * j + 3 * k <= x + 2 * y + 3 * z){
          printf("sushi(%lld, %lld, %lld) = %f\n", i, j, k, sushi(i,j,k));
        }
      }
    }
  }
  */
  printf("%.10f\n", sushi(x,y,z));
}
