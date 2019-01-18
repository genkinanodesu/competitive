#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;
   typedef pair<ll, ll> Pii;

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

const ll MAX_N = 1e5;
struct edge{
  ll to, cost;
};
vector<edge> g[MAX_N] = {}; //g[i] = (edges from i)
ll dist[MAX_N] = {};
ll N;
ll parent[MAX_N];
void dfs(ll v, ll par){
  parent[v] = par;
  for (edge& e: g[v]){
    if(e.to == par) continue;
    dfs(e.to, v);
    chmax(dist[v], dist[e.to] + e.cost);
  }
}

int main(){
  cin >> N;
  REP(i, N - 1){
    ll a, b, w;
    cin >> a >> b >> w;
    g[a].pb((edge) {b, w});
    g[b].pb((edge) {a, w});
  }
  dfs(0, -1);
  ll farthest = 0;
  while(dist[farthest] != 0){
    for (auto& e: g[farthest]){
      if(e.to == parent[farthest]) continue;
      if(dist[e.to] + e.cost == dist[farthest]){
        farthest = e.to;
        break;
      }
    }
  }
REP(i, N) dist[i] = 0;
dfs(farthest, -1);
cout << dist[farthest] << endl;
}
/*
Pii add(Pii x, Pii y){
  return mp(x.first + y.first, x.second + y.second);
}
const ll MAX_N = 1e5;
ll N;
bool reached[MAX_N] = {};
ll memo[MAX_N] = {};
//adj_node[i] = {{iに隣接する頂点, その距離}の可変長配列}
vector<Pii> adj_node[MAX_N] = {};

void dfs(ll v){
  //vから深さ優先探索, もっとも遠い頂点を求める
  reached[v] = true;
  ll temp = 0;
  for (Pii& u : adj_node[v]){
    if(!reached[(u).first]){
      dfs((u).first);
      chmax(temp, memo[(u).first] + (u).second);
    }
  }
  memo[v] = temp;
}


int main(){
  cin >> N;
  REP(i, N -1){
    ll si, ti, wi;
    cin >> si >> ti >> wi;
    adj_node[si].pb(mp(ti, wi));
    adj_node[ti].pb(mp(si, wi));
  }
  dfs(0);
//  cout << memo[0] << endl;
  ll temp = 0;
  REP(i, N) reached[i] = false;
  while(memo[temp] != 0){
    for (Pii& u: adj_node[temp]){
      if (!reached[(u).first]){
        reached[(u).first] = true;
        if (memo[temp] == memo[(u).first] + (u).second) {
          temp = (u).first;
//          printf("temp = %lld\n", temp);
          break;
        }
      }
    }
  }
//  cout << temp << endl;
  REP(i, N) {
    memo[i] = 0; reached[i] = false;
  }
  dfs(temp);
  printf("%lld\n", memo[temp]);
}
*/
