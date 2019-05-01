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

const ll MAX_N = 1e5 + 1;
ll n, m, k;
struct edge{
  ll from;
  ll to;
  ll dist;
};
ll min_dist[MAX_N];
edge E[MAX_N * 2];
vector<edge> G[MAX_N];
bool reached[MAX_N] = {};

/*
void dfs(const ll& node, const edge& prev, const set<int>& s){
  for(edge e : G[node]){
    if(prev.from == e.to) continue;
    if(s.find(e.to) != s.end()) continue;
    (prev.dist == e.dist) ? chmin(min_dist[e.to], min_dist[node]) : chmin(min_dist[e.to], min_dist[node] + 1);
    set<int> s_new = s; s_new.insert(e.from);
    dfs(e.to, e, s_new);
  }
}
*/
void dfs(const ll& node, const edge& prev){
  reached[node] = true;
  for(edge e : G[node]){
    if(reached[e.to]) continue;
    (prev.dist == e.dist) ? chmin(min_dist[e.to], min_dist[node]) : chmin(min_dist[e.to], min_dist[node] + 1);
    dfs(e.to, e);
  }
  reached[node] = false;
}
int main(){
  cin >> n >> m >> k;
  REP(i, n) min_dist[i] = INF;
  min_dist[0] = 0;

  REP(i, m){
    ll a, b, c; scanf("%lld%lld%lld", &a, &b, &c);
    a--; b--;
    E[2 * i] = {a, b, c};
    E[2 * i + 1] = {b, a, c};
    G[a].pb({a, b, c}); G[b].pb({b, a, c});
  }
  edge start_edge = {-1, 0, INF};
  dfs(0, start_edge);
//  REP(i, n) printf("min_dist[%lld] = %lld\n", i, min_dist[i]);
  cout << ((min_dist[n - 1] < INF) ? min_dist[n - 1] * k : -1) << endl;
}
