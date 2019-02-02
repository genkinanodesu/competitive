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
struct UnionFind {
  vector<long long> data;
  UnionFind(long long size) : data(size, -1) { }
  bool unionSet(long long x, long long y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(long long x, long long y) {
    return root(x) == root(y);
  }
  long long root(long long x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  long long size(long long x) {
    return -data[root(x)];
  }
};

const ll MAX_N = 50, MAX_M = (MAX_N * MAX_N) / 2;
ll N, M;
Pii e[MAX_M];

int main(){
   cin >> N >> M;
   REP(i, M){
      ll a, b; cin >> a >> b; a--; b--;
      e[i] = mp(a, b);
   }
   ll ans = 0;
   REP(i, M){
      UnionFind T(N);
      REP(j, M){
         if(i == j) continue;
         T.unionSet(e[j].first, e[j].second);
      }
//      cout << T.size(0) << endl;
      if(T.size(0) != N) ans ++;
   }
   cout << ans << endl;
}
