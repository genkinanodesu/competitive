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

const ll MAX_H = 400, MAX_W = 400;
ll H, W;
bool grid[MAX_H][MAX_W];
bool is_reached[MAX_H][MAX_W];

bool in_grid(ll x, ll y) {
   return ((0 <= x && x < H) && (0 <= y && y < W));
}

int main(){
   cin >> H >> W;
   REP(i, H){
      string s; cin >> s;
      REP(j, W){
         (s[j] == '#') ? grid[i][j] = 1 : grid[i][j] = 0;
      }
   }
   ll ans = 0;
   ll b = 0, w = 0;
   REP(i, H){
      REP(j, W){
         if(is_reached[i][j]) continue;
         b = 0, w = 0;
         queue<Pii> que;
         que.push(mp(i, j));
         is_reached[i][j] = true;
         while(!que.empty()){
            Pii p = que.front();
            que.pop();
            ll x = p.first, y = p.second;
            (grid[x][y]) ? b++ : w++;
            REP(k, 4){
               ll X = x + dx[k], Y = y + dy[k];
               if(in_grid(X, Y) && (!is_reached[X][Y]) && (grid[x][y] ^ grid[X][Y])){
                  que.push(mp(X, Y));
                  is_reached[X][Y] = true;
               }
            }
         }
         ans += b * w;
//         printf("i = %lld, j = %lld, b = %lld, w = %lld\n", i, j, b, w);
      }
   }
   cout << ans << endl;
}
