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
   #define RSORT(x) sort((x).rbegin(), (x).rend()
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


   ll dx[4]={1,0,-1,0};
   ll dy[4]={0,1,0,-1};

ll bin_search(ll x){
  // nC2 <= x < (n+1)C2を満たすnを求める
  ll lb = 2, ub = INF;
  while(ub - lb > 1){
    ll mid = (lb + ub) / 2;
    if((mid * (mid-1) / 2) <= x) ub = mid;
    else lb = mid;
    cout << mid << endl;
  }
  return lb;
}
ll comb(ll x){
  return (x * (x-1) / 2);
}
const ll MAX_N = 1e5;
ll N, K, R;
vector<ll> ans;
int main(){
  cin >> N >> K >> R;
  if (R > ((N + 1 - K) * (N - K) / 2)){
    cout << "No Luck\n";
    return 0;
  }
  ll temp = K + 1;
  while (comb(temp - K + 1) < R) temp++;
//  cout << "temp =" << temp << endl;
  REP(i, temp - 1) ans.pb(temp - i - 1);
  ll ret = R - comb(temp - K);
  ans.insert(ans.begin() + temp - ret - 1, temp);
  FOR(j, temp + 1, N + 1){
    ans.pb(j);
  }
  REP(i, N) {
    if(i!= 0) printf(" ");
    printf("%lld", ans[i]);
  }
  printf("\n");
}
