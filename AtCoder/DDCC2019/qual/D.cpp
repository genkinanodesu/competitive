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

   int dx[4]={1,0,-1,0};
   int dy[4]={0,1,0,-1};
/*
ll gcd(ll a, ll b) {
  return b != 0 ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}
// a x + b y = gcd(a, b)
ll extgcd(ll a, ll b, ll &x, ll &y) {
  ll g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}
*/

inline long long mod(long long a, long long m) {
    return (a % m + m) % m;
}

long long extGcd(long long a, long long b, long long &p, long long &q) {  
    if (b == 0) { p = 1; q = 0; return a; }  
    long long d = extGcd(b, a%b, q, p);  
    q -= a/b * p;  
    return d;  
}

// 中国剰余定理
// リターン値を (r, m) とすると解は x ≡ r (mod. m)
// 解なしの場合は (0, -1) をリターン
pair<long long, long long> ChineseRem(const vector<long long> &b, const vector<long long> &m) {
  long long r = 0, M = 1;
  for (int i = 0; i < (int)b.size(); ++i) {
    long long p, q;
    long long d = extGcd(M, m[i], p, q); // p is inv of M/d (mod. m[i]/d)
    if ((b[i] - r) % d != 0) return make_pair(0, -1);
    long long tmp = (b[i] - r) / d * p % (m[i]/d);
    r += M * tmp;
    M *= m[i]/d;
  }
  return make_pair(mod(r, M), M);
}

ll sum_digit(ll x, ll k){
   ll ans = 0;
   while (x > 0){
      ans += x % k;
      x /= k;
   }
   return ans;
}

vector<ll> A(29), A1(29), B(29);
int main(){
   REP(i, 29){
      cin >> A[i];
      A1[i] = A[i] % (i + 1);
      B[i] = i + 1;
   }
   pair<ll, ll> X = ChineseRem(A1, B);
   if (X.second < 0 || X.first > 1e12) cout << "invalid\n";
   else{
      ll n = X.first;
      bool flag = true;
      FOR(i, 2, 31){
         if (sum_digit(n, i) != A[i - 2]){
            flag = false;
            break;
         }
      }
      flag ? cout << n << endl : cout << "invalid\n";

   }

}