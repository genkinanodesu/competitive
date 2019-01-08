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
string dp1[MAX_str+1] = {};
string dp2[MAX_str+1] = {};
int main(){
  cin >> s >> t;
  REP(i, s.size()){
    REP(j, t.size()+1) {
      dp1[j] = dp2[j];
      dp2[j] = "";
    }
    REP(j, t.size()){
      if (dp2[j].size() > dp1[j+1].size()) dp2[j+1] = dp2[j];
      else dp2[j+1] = dp1[j+1];
      if (s[i] == t[j] && dp1[j].size() + 1 > dp2[j+1].size()){
        dp2[j+1] = dp1[j] + s[i];
      }
//      printf("s = %s, t = %s : dp2[%lld] = %s\n", s.substr(0, i + 1).c_str(), t.substr(0, j + 1).c_str(),j+1, dp2[j+1].c_str());
    }
  }
  cout << dp2[t.size()] << endl;
}
