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

const ll MAX_N = 400;
ll N;
ll a[MAX_N] = {}, s[MAX_N + 1] = {};
ll dp[MAX_N + 1][MAX_N + 1];

ll slime(ll n, ll m){
   //a[n],...,a[m]を合体させるコスト
   if (n == m) return 0;
   else if (dp[n][m] >= 0) return dp[n][m];
   else{
      ll ans = INF;
      FOR(k, n, m){
         chmin(ans, s[m + 1] - s[n] + slime(n, k) + slime(k + 1, m));
      }
      dp[n][m] = ans;
      return ans;
   }
}

int main(){
   cin >> N;
   REP(i, N) {
      //s[i + 1] = a[0] + ... + a[i]
      cin >> a[i];
      s[i + 1] = s[i] + a[i];
   }
   REP(i, N){
      REP(j, N){
         dp[i][j] = -1;
      }
   }
   cout << slime(0, N - 1) << endl;


}
