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
const ll MAX_N = 1e4;
ll n;
ll a[MAX_N + 1];
Vi list_of_primes(ll n){
  // return list of primes p <= n
  //primes[i] != 0 iff i is prime.
  Vi primes(n);
  FOR(i, 2, n){
   primes[i] = i;
  }
  for (ll i = 2; i*i < n; ++i)
   if (primes[i])
     for (ll j = i*i; j < n; j+=i)
       primes[j] = 0;
  primes.erase(remove(primes.begin(), primes.end(), 0), primes.end());
  return primes;
}
Vi prime_factors(ll n){
  // return list of prime factors of n.
  if(n == 1) return {};
  for(ll i = 2; i * i <= n; i++){
    if(n % i == 0){
      Vi ans = prime_factors(n / i);
      ans.pb(i);
      sort(ans.begin(), ans.end());
      ans.erase(unique(ans.begin(), ans.end()), ans.end());
      return ans;
    }
  }
  return {n};
}
bool hantei(ll p){
//  cout << "p = " << p << endl;
  if(a[0] % p != 0) return false;
  Vi a_red(p - 1, 0);
  REP(i, n + 1){
    a_red[i % (p - 1)] += a[i];
  }
  REP(i, p - 1){
//    printf("a_red[%d] == %d\n", i, a_red[i]);
    if (a_red[i] % p != 0) return false;
  }
  return true;
}
int main(){
  cin >> n;
  ll d = 0;
  REP(i, n + 1){
    cin >> a[n - i];
    d = gcd(d, abs(a[n - i]));
  }
  Vi P1 = prime_factors(d); //係数全ての最大公約数は必ず条件を満たす.
  Vi P2 = list_of_primes(n + 1);
  for(auto &p : P2){
    if(hantei(p)) P1.pb(p);
  }
  SORT(P1);
  for(auto &p : P1){
    cout << p << endl;
  }
}
