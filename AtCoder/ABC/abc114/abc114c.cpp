#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;
   typedef pair<ll, ll> P;

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

   ll gcd(int a,int b){return b?gcd(b,a%b):a;};

   ll dx[4]={1,0,-1,0};
   ll dy[4]={0,1,0,-1};

ll N;
vector<ll> Num[2][2][2] = {};

vector<ll> func(vector<ll> v){
  if (v.empty()) return {0};
  vector<ll> ans;
  ans.pb(0);
  vector<ll> sets[11];
  sets[0] = {0};
  REP(d, 10){
    for (auto &e : sets[d]){
      for (auto &m : v){
        if(e * 10 + m <= N){
          sets[d + 1].pb(e * 10 + m);
        }
      }
    }
  ans.insert(ans.end(), sets[d + 1].begin(), sets[d + 1].end());
  }
  return ans;
}
int main(){
  cin >> N;
  REP(i, 2){
    REP(j, 2){
      REP(k, 2){
        vector<ll> v = {};
        if(i == 1) v.pb(3);
        if(j == 1) v.pb(5);
        if(k == 1) v.pb(7);
        Num[i][j][k] = func(v);
        SORT(Num[i][j][k]);
//        printf("i = %lld, j = %lld, k = %lld, %lld\n", i, j, k, Num[i][j][k].size());
      }
    }
  }
  ll ans = 0;
  REP(i, 2){
    REP(j, 2) {
      REP(k, 2){
        ans += (((i + j + k) % 2) * 2 - 1) * (Num[i][j][k].size());
      }
    }
  }
  cout << ans << endl;
}
