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
   ll pow(ll a, ll b, ll m){if (b == 0) return 1; else if (b % 2 == 0) return (pow(a * a, b / 2, m) % m); else return (pow(a * a, b / 2) * a) % m;}
   ll residue(ll a, ll m){return ((a % m) + m) % m;};

   ll dx[4]={1,0,-1,0};
   ll dy[4]={0,1,0,-1};

ll bs(ll x, const Vi a, const Vi b){
  //a + bのうちにx以上の要素がいくつあるか?
  //a, bはソートずみ
  ll temp = 0;
  for(const auto &e : a){
    temp += b.end() - lower_bound(b.begin(), b.end(), x - e);
  }
  return temp;
}
int main(){
  ll x, y, z, k; cin >> x >> y >> z >> k;
  Vi A(x), B(y), C(z); SORT(A), SORT(B), SORT(C);
  REP(i, x) cin >> A[i];
  REP(i, y) cin >> B[i];
  REP(i, z) cin >> C[i];

  Vi AB;
  REP(i, x){
    REP(j, y){
      AB.pb(A[i] + B[j]);
    }
  }
  SORT(AB);
  REP(k, 20){
    cout << bs(k, AB, C) << endl;
  }
  REP(i, k){
    ll lb = 0, ub = 4 * 1e15;
    while(ub - lb > 1){
      ll mid = (ub + lb) / 2;
      (bs(mid, AB, C) >= k + 1) ? lb = mid : ub = mid;
    }
    cout << lb << endl;
  }
}
