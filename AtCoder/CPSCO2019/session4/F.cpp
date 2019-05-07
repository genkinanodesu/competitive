//ACしていない！！！！！！

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
     vector<long long> component(long long x){
       vector<long long> v;
       REP(i, data.size()){
         if(findSet(x, i)) v.push_back(i);
       }
       return v;
     }
   };
   struct edge{
     ll to, from, weight;
   };

const ll MAX_K = 300;
ll dist[MAX_K][MAX_K];
ll depth[MAX_K][MAX_K] = {};

vector<edge> lost_tree(ll root, const Vi& v){
  // for(auto &i: v) for(auto &j : v) printf("depth[%lld][%lld] = %lld, ", i, j, depth[i][j]);
  // printf("\n");
  ll x = v.size();
  if(x == 1){
    edge e = {root, v[0], depth[v[0]][v[0]]};
    depth[v[0]][v[0]] == 0;
    return {e};
  }
  vector<bool> check(x, false);
  UnionFind uf(x);
  vector<edge> ans = {};
  ll next_root = root + 1;
  REP(i, x){
    REP(j, x){
      if(depth[i][j] != 0) uf.unionSet(i, j);
    }
  }
  REP(i, x){
    if(check[i]) continue;
    Vi comp_i = uf.component(i);
    for(auto &j : comp_i) check[j] = true;
    printf("%lldと共通の根を持つ頂点は", i);
    for(auto &j : comp_i) printf("%lld, ", j);
    printf("です.\n");

    ll min_depth = INF;
    for(auto &j : comp_i) for(auto &k : comp_i) chmin(min_depth, depth[j][k]);
    for(auto &j : comp_i) for(auto &k : comp_i) depth[j][k] -= min_depth;
    if(min_depth!= 0) ans.pb(edge{root, next_root, min_depth});
    printf("min_depth = %lld\n", min_depth);
    vector<edge> t = lost_tree(next_root, comp_i);
    printf("t.size() = %lld\n", t.size());
    ans.insert(ans.end(), t.begin(), t.end());
    next_root++;
  }
  return ans;
}
int main(){
  ll k; cin >> k;
  REP(i, k) REP(j, k) cin >> dist[i][j];
  REP(i, k) depth[i][i] = dist[k - 1][i];
  REP(i, k) REP(j, k) depth[i][j] = (depth[i][i] + depth[j][j] - dist[i][j]) / 2;
  Vi v(k - 1); REP(i, k- 1) v[i] = i;
  vector<edge> tree = lost_tree(k - 1, v);
  cout << tree.size() << endl;
  for(auto &e : tree){
    cout << e.to + 1 << ' ' << e.from + 1 << ' ' << e.weight << endl;
  }

}
