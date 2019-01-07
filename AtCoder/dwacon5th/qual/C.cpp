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

const ll MAX_N = 1e6, MAX_Q = 75;
ll N, Q;
string S;
ll K[MAX_Q];

ll a[MAX_N * 2] = {};
ll b[MAX_N * 2] = {};
ll c[MAX_N * 2] = {};
ll A[MAX_N * 2 + 1], B[MAX_N * 2 + 1], C[MAX_N * 2 + 1];

ll DMC(ll k){
   ll F[MAX_N + 1] = {};
   REP(i, N){
      F[i + 1] = F[i] + a[i] * C[i + k];
   }
   ll ans = 0;
   REP(y, N){
      ans += b[y] * (F[y] - F[max(0ll, y - k + 2)] - C[y + 1] * (A[y] - A[max(0ll, y - k + 2)]));
   }
   return ans;
}

int main(){
   cin >> N >> S >> Q;
   REP(i, Q){
      cin >> K[i];
   }
   REP(i, N){
      a[i] = (S[i] == 'D');
      b[i] = (S[i] == 'M');
      c[i] = (S[i] == 'C');
   }
   A[0] = 0;
   B[0] = 0;
   C[0] = 0;
   REP(i, 2 * N){
      A[i + 1] = A[i] + a[i];
      B[i + 1] = B[i] + b[i];
      C[i + 1] = C[i] + c[i];
   }
   REP(i, Q){
      cout << DMC(K[i]) << endl;
   }
}