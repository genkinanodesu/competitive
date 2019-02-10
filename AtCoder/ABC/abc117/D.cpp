#include <bits/stdc++.h>
using namespace std;

   typedef  long long ll;
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

//   ll dx[4]={1,0,-1,0};
 //  ll dy[4]={0,1,0,-1};
const ll MAX_N = 1e5, MAX_K = 50;
ll N, K;
ll A[MAX_N] = {};
ll B[MAX_K][MAX_N] = {};
ll C[MAX_K] = {};
ll s = 0;
ll log2(ll x){
   if(x == 1) return 0;
   return log2(x / 2) + 1;
}
ll f_max(ll x){
   //x以下のfの最大値
   if (x == 0) return s;
   if(x + 1 == pow(2, log2(x + 1))){
      //xが2べき - 1のとき
      ll ans = 0;
      REP(j, log2(x) + 1){
         ans += (1ll << j) * max(C[j], N - C[j]);
      }
      FOR(j, log2(x) + 1, 50){
         ans += (1ll << j) * C[j];
      }
      return ans;
   }
   else{
      ll fmax1 = f_max(pow(2, log2(x)) - 1); // 0 - 2^k - 1でのmax
      ll fmax2 = pow(2, log2(x)) * (N - 2 * C[log2(x)]) + f_max(x - pow(2, log2(x))); // x - 2^kでのmax
      //printf("fmax1 = %lld, fmax2 = %lld\n", fmax1, fmax2);
      return max(fmax1, fmax2);   
   }   
}
int main(){
   cin >> N >> K;
   REP(i, N) {
      cin >> A[i];
      s += A[i];
   }
   REP(j, 50){
      REP(i, N){
         B[j][i] = (A[i] >> j) & 1;
         C[j] += B[j][i];
      }
   }
   cout << f_max(K) << endl;
}
