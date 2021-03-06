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

Vi mul(VVi a, Vi b, ll m){
  ll x = a.size(), y = a[0].size(), y1 = b.size();
  assert(y == y1);
  REP(i, x) REP(j, y) {
    a[i][j] = residue(a[i][j], m);
  }
  REP(i, y) b[i] = residue(b[i], m);
  Vi c(x, 0);
  REP(i, x) REP(j, y){
    c[i] += a[i][j] * b[j] % m; c[i] %= m;
  }
  return c;
}
VVi mul(VVi a, VVi b, ll m){
  //a * b 要素はmで割ったあまり
  ll x = a.size(), y1 = a[0].size(), y2 = b.size(), z = b[0].size();
  assert(y1 == y2);
  ll y = y1;
  REP(i, x) REP(j, y) a[i][j] = residue(a[i][j], m);
  REP(i, y) REP(j, z) b[i][j] = residue(b[i][j], m);
  VVi c(x, Vi(z, 0));
  REP(i, x) REP(j, z) REP(k, y){
    c[i][j] += (a[i][k] * b[k][j]) % m; c[i][j] %= m;
  }
  return c;
}
VVi pow(VVi a, ll n, ll m){
  if(n == 0) {
    ll x = a.size();
    VVi I(x, Vi(x, 0));
    REP(i, x) I[i][i] = 1;
    return I;
  }
  if(n % 2 == 0) {
    VVi b = mul(a, a, m);
    return pow(b, n / 2, m);
  }
  else return mul(pow(a, n - 1, m), a, m);
}

int main(){
  ll l, a, b, m; cin >> l >> a >> b >> m;
  Vi p(18);
  REP(i, 18){
    ll x = max(0ll, (pow(10ll, i) - a + b - 1) / b); chmin(x, l);
    ll y = max(0ll, (pow(10ll, i + 1) - a + b - 1) / b); chmin(y, l);
    p[i] = y - x;
//    printf("p[%lld] = (%lld桁の項数) = %lld\n", i, i + 1, p[i]);
  }
  Vi X = {0, residue(a - b, m), 1};
  VVi Y = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  REP(i, 18){
    VVi A = {{pow(10, i + 1, m), 1, b}, {0, 1, b}, {0, 0, 1}};
    Y = mul(pow(A, p[i], m), Y, m);
//    printf("i = %lld, X[0] = %lld, X[1] = %lld, X[2] = %lld\n", i, X[0], X[1], X[2]);
  }
  Vi Z = mul(Y, X, m);
  cout << Z[0] << endl;
}
