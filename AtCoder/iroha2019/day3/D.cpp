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

ll n;
bool grid[9][9] = {};
bool in_grid(ll x, ll y){
  return (0 <= x && x < n && 0 <= y && y < n && grid[x][y] == true);
}
char mv[5] = {'D', 'R', 'U', 'L', '-'};
int main(){
  cin >> n;
  REP(i, n){
    string s; cin >> s;
    REP(j, n){
      char c = s[j];
      (c == '.') ? grid[i][j] = true : grid[i][j] = false;
    }
  }
  Pii me = mp(2ll, 2ll);
  Pii feedback = mp(-1ll, -1ll);
  while(true){
    // printf("before move : me = %lld, %lld\n", me.first, me.second);
    ll x = feedback.first, y = feedback.second;
    // printf("x = %lld, y = %lld\n", x, y);
    if(x == -2 || x == -3) return 0;
    if(x > 0 && (x + y + me.first + me.second) % 2 != 0){
      REP(k, 4){
        ll p = me.first + dx[k], q = me.second + dy[k];
        // printf("(p = %lld, q = %lld) = %lld\n", p, q, in_grid(p - 1, q - 1));
        // dump(in_grid(p - 1, q - 1) && !((p, q) == (x, y)))
        // dump((p, q) == (x, y))
        if(in_grid(p - 1, q - 1) && Pii(p, q) != Pii(x, y)){
          me = mp(p, q);
          cout << mv[k] << endl;
          break;
        }
      }
    }
    else {cout << mv[4] << endl;}
    // printf("after move: me = %lld, %lld\n", me.first, me.second);
    cin >> feedback.first >> feedback.second;
  }
}
