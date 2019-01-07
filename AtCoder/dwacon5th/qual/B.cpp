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

   int gcd(int a,int b){return b?gcd(b,a%b):a;};

   int dx[4]={1,0,-1,0};
   int dy[4]={0,1,0,-1};

const ll MAX_N = 1e3;
ll N, K;
ll a[MAX_N];
ll s[MAX_N + 1] = {}; // 累積和

vector<ll> v;

void solve(){
   ll ans = 0;
   REP(i, 51){
      if ((v.end() - lower_bound(v.begin(), v.end(), 1ull << (50 - i)))>= K){
         ans += 1ull << (50 - i);
         REP(j, v.size()){
            if (v[j] >= (1ull << (50 - i))) v[j] -= (1ull << (50 - i));
            else v[j] = 0;
         }
      }
      else{
         REP(j, v.size()){
            v[j] &= ((1ull << (50 - i)) - 1);
         }
      }
      SORT(v);
   }
   cout << ans << endl;
}

int main(){
   cin >> N >> K;
   REP(i, N) {
      cin >> a[i];
      s[i + 1] = s[i] + a[i];
   }
   FOR(i, 0, N){
      FOR(j, i, N){
         v.pb(s[j + 1] - s[i]);
      }
   }
   SORT(v);
   solve();
}