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
   ll residue(ll a, ll m){return ((a % m) + m) % m;};

   ll dx[4]={1,0,-1,0};
   ll dy[4]={0,1,0,-1};
const ll MAX_N = 1e5;
ll N, M;
Vi G_in[MAX_N] = {}; //iの親
Vi G_out[MAX_N] = {}; //iの子
ll parent[MAX_N];
ll dist[MAX_N] = {};
ll root = -1;
ll d(ll x){
   if (x == root) return 0;
   if (dist[x] > 0) return dist[x];
   else{
      ll ans = 0;
      for(auto &e: G_in[x]){
         chmax(ans, d(e) + 1);
      }
      dist[x] = ans;
      return ans;
   }
}
int main(){
   cin >> N >> M;
   REP(i, N + M - 1){
      ll A, B;
      cin >> A >> B;
      A--; B--;
      //edge A -> B
      G_out[A].pb(B);
      G_in[B].pb(A);
   }
   REP(i, N) parent[i] = -1;
   REP(i, N){
      if (G_in[i].empty()) root = i;
   }
   REP(i, N){
      for(auto &e: G_in[i]){
         if (d(i) == d(e) + 1) parent[i] = e;
      }
   }
   REP(i, N) cout << parent[i] + 1 << endl;
}
