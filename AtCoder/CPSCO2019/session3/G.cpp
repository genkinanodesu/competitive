#include <bits/stdc++.h>
using namespace std;
#define double long double

   typedef long long ll;
   typedef pair<ll, ll> Pii;
   typedef vector<ll> Vi;
   typedef vector<Vi> VVi;

   const double EPS = (1e-10);
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

const ll MAX_N = 1e5;
ll n, X;
ll A = 0;
ll a[MAX_N], x[MAX_N];

double error_ith(ll i, ll x){
  return abs((double)x / (double)a[i] - (double)X / (double)A);
}

int main(){
  //input
  cin >> n >> X;
  REP(i, n) {cin >> a[i]; A += a[i];}
  REP(i, n) x[i] = 0;

  vector<tuple<double, ll, ll>> v; // 変化量, i番目に登場する, 登場回数. vを昇順にソートし, 登場回数の合計をX回にする.
  REP(i, n){
    //-EPS * iを足しておくことで, 同じ値に関してはiが大きいほうが昇順で先にくるようにする.
    ll xi = a[i] * X / A;
    if(xi * A == a[i] * X){
      v.pb(make_tuple(-1.0 / (double)a[i] - EPS * i, -i, xi));
      v.pb(make_tuple( 1.0 / (double)a[i] - EPS * i, -i, X - xi));
    }
    else{
      double e = error_ith(i, xi + 1) - error_ith(i, xi);
      v.pb(make_tuple(-1.0 / (double)a[i] - EPS * i, -i, xi));
      v.pb(make_tuple( 1.0 / (double)a[i] - EPS * i, -i, X - xi - 1));
      v.pb(make_tuple(e - EPS * i, -i, 1));
    }
  }
  sort(v.begin(), v.end());
  ll cnt = 0;
  // for(auto &elem : v){
  //   double e = get<0>(elem);
  //   ll i = - get<1>(elem), c = get<2>(elem);
  //   printf("e = %f, i = %lld, c = %lld\n", e, i, c);
  // }
  for(auto &elem : v){
    if(cnt >= X) break;
    ll i = - get<1>(elem);
    x[i] += min(get<2>(elem), X - cnt);
    cnt = min(X, cnt + get<2>(elem));
  }
  REP(i, n) cout << x[i] << endl;
}
