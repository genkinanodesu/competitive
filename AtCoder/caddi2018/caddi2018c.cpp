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

   int gcd(int a,int b){return b?gcd(b,a%b):a;};

   int dx[4]={1,0,-1,0};
   int dy[4]={0,1,0,-1};


ll k, n;
vector<ll> factorize(ll n){
  //nの素因数の配列を返す
  vector<ll> P = {};
  ll i = 2;
  while (i * i <= n){
    if (n % i == 0){
      P.pb(i);
      n /= i;
    }
    else {i++;}
  }
  P.pb(n);
  return P;
}

int main(){
  cin >> k >> n;
  vector<ll> P = factorize(n);
  set<ll> S(P.begin(), P.end());
  ll ans = 1;
  for (auto i = S.begin(); i != S.end(); i++){
    ll cnt = upper_bound(P.begin(), P.end(), *i) - lower_bound(P.begin(), P.end(), *i);
    ans *= pow(*i, cnt / k);
  }
  cout << ans << endl;

}
