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
const ll MAX_N = 100;
ll N;
ll x[MAX_N], y[MAX_N], h[MAX_N];

ll mdis(ll x1, ll y1, ll x2, ll y2){
   return abs(x1 - x2) + abs(y1 - y2);
}
int main(){
   cin >> N;
   REP(i, N) cin >> x[i] >> y[i] >> h[i];
   ll argmax_h = -1; ll max_h = -1;
   REP(i, N){
      if(chmax(max_h, h[i])) argmax_h = i;
   }

   REP(i, 101){
      REP(j, 101){
         ll flag = true;
         ll height = max_h + mdis(x[argmax_h], y[argmax_h], i, j);
         REP(k, N){
            if(h[k] != max(0ll, height - mdis(i, j, x[k], y[k]))){
               flag = false;
               break;
            }
         }
         if (flag){
            printf("%lld %lld %lld\n", i, j, height);
            return 0;
         }
      }
   }
}
