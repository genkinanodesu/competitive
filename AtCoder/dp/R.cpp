#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;
   typedef pair<ll, ll> Pii;
   typedef vector<ll> vi;
   typedef vector<vector<ll>> vvi;


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

   // O( n )
   vvi identity(ll n) {
     vvi A(n, vi(n));
     REP(i, n) A[i][i] = 1;
     return A;
   }
   // O( n )
   ll inner_product(const vi &a, const vi &b) {
     ll ans = 0;
     REP(i, a.size()){
       ans += a[i] * b[i];
     }
     return ans;
   }
   // O( n^2 )
   vi mul(const vvi &A, const vi &x) {
     vi y(A.size());
     for (ll i = 0; i < A.size(); ++i)
       for (ll j = 0; j < A[0].size(); ++j){
         y[i] = A[i][j] * x[j];
         y[i] %= MOD;
       }
     return y;
   }
   // O( n^3 )
   vvi mul(const vvi &A, const vvi &B) {
     vvi C(A.size(), vi(B[0].size()));
     for (ll i = 0; i < C.size(); ++i)
       for (ll j = 0; j < C[i].size(); ++j)
         for (ll k = 0; k < A[i].size(); ++k){
           C[i][j] += A[i][k] * B[k][j];
           C[i][j] %= MOD;
         }
     return C;
   }
   // O( n^3 log e )
   vvi pow(const vvi &A, ll e) {
     return e == 0 ? identity(A.size())  :
        e % 2 == 0 ? pow(mul(A, A), e/2) : mul(A, pow(A, e-1));
   }

const ll MAX_N = 50;
ll N, K;

int main(){
  cin >> N >> K;
  vvi a(N, vi(N));
  REP(i, N){
    REP(j, N){
      cin >> a[i][j];
    }
  }
  vvi b = pow(a, K);
  ll ans = 0;
  REP(i, N){
    REP(j, N){
      ans += b[i][j];
      ans %= MOD;
    }
  }
  cout << ans << endl;
}
