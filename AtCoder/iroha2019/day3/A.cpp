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

int main(){
  ll T[26];
  REP(i, 26) cin >> T[i];
  cout << T[0] - T[1] << endl;
  cout << T[2] + T[3] << endl;
  cout << max(0ll, T[5] - T[4] + 1) << endl;
  cout << (T[6] + T[7] + T[8] + 3) / 3 << endl;

  string s[8] = {"a", "aa", "aaa", "aaai", "aaaji", "aabaji", "agabaji", "dagabaji"};
  cout << s[T[9] - 1] << endl;
  ll k = T[10], l = T[11], m = T[12];
  ll fav1 = k % 59, fav2;
  while(fav1 % 61 != l % 61) fav1 += 59;
  fav1 += (59 * 61) * (m - 1);
  Vi perf = {	6, 28, 496, 8128, 33550336, 8589869056, 137438691328, 2305843008139952128};
  for(auto e : perf){
    if(abs(e - fav1) >= T[13]){
      fav2 = e;
      break;
    }
  }
  cout << min(fav1, fav2) << endl << max(fav1, fav2) << endl;
  cout << (T[14] + T[15] + T[16]) * (T[17] + T[18] + T[19]) * (T[20] + T[21] + T[22]) * (T[23] + T[24] + T[25]) % 9973 << endl;
}
