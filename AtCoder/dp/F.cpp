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

string s, t;
const ll MAX_str = 3e3;
ll dp[MAX_str + 1][MAX_str + 1] = {};

int main(){
  cin >> s >> t;
  REP(i, s.size()){
    REP(j, t.size()) {
      dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
      if (s[i] == t[j]) chmax(dp[i+1][j+1], dp[i][j] + 1);
    }
  }
  ll i = s.size() - 1, j = t.size() - 1;
  string ans;
  while (i >= 0 && j >= 0){
    if (dp[i + 1][j + 1] == dp[i][j + 1]) i--;
    else if (dp[i + 1][j + 1] == dp[i + 1][j]) j--;
    else {
      ans.insert(ans.begin(), s[i]); 
      i--;
      j--;
    }
  }
  cout << ans << endl;
}
