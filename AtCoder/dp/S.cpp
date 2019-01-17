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

const ll MAX_Klen = 1e5 + 1, MAX_D = 100;
string K;
ll K_len;
ll D;
ll dp[MAX_Klen + 1][MAX_D][2] = {};

inline ll mod(ll a, ll m){
  return ((a % m) + m) % m;
}

ll digit_dp(ll i = 0, ll x = 0, bool flag = true){
  if (dp[i][x][flag] >= 0) return dp[i][x][flag];
  else if (i == K_len){
    dp[i][x][flag] = (x == 0);
    return (x == 0);
  }
  else{
    ll ans = 0;
    if (flag){
      REP(k, K[i] - '0'){
        ans += digit_dp(i + 1, mod(x - k, D), false);
        ans %= MOD;
      }
      ans += digit_dp(i + 1, mod(x - (K[i] - '0'), D) , true);
      ans %= MOD;
    }
    else{
      REP(k, 10){
        ans += digit_dp(i + 1, mod(x - k, D), false);
        ans %= MOD;
      }
    }
    ans %= MOD;
    dp[i][x][flag] = ans;
    return ans;
  }
}
int main(){
  cin >> K >> D;
  K_len = K.size();
  REP(i, K_len + 1){
    REP(x, D){
      dp[i][x][true] = -1, dp[i][x][false] = -1;
    }
  }
  cout << mod(digit_dp() - 1, MOD)<< endl;
}
