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
const ll MAX_Q = 2000;
ll Q;
vector<ll> p = {};
vector<ll> group[8] = {};

ll G[56][56];

bool hantei(){
   //求めたグラフGが正答になっているかを判定する
   return true;
}
int main(){
   //input
   cin >> Q;
   REP(i, Q) {
      ll pi; 
      cin >> pi;
      p.pb(pi);
   }
   SORT(p);
   REP(i, 56) REP(j, 56) G[i][j] = -1;
   //長さ1~2000をグループ分け
   ll x = 1;
   while (x <= 2000){
      if (!binary_search(ALL(p), x)) {
         x++;
      }
      else{
         ll flag = binary_search(ALL(p), x + 1)
            + binary_search(ALL(p), x + 2) * 2
            + binary_search(ALL(p), x + 3) * 4;
//         printf("x = %lld, flag = %lld\n", x, flag);
         group[flag].pb(x);
         x += 4;
      }
   }
//   REP(i, 8) printf("group[%lld]の個数は%lld\n", i, (ll)group[i].size() );

   G[0][1] = 1, G[0][2] = 2, G[0][3] = 3;
   REP(i, 29) G[0][i + 4] = 0;
   ll tmp1 = 4, tmp2 = 33;
   REP(i, 8){
      G[0][tmp1] = 0;
      if (i & 1) G[1][tmp1] = 0 ;
      if ((i >> 1) & 1) G[2][tmp1] = 0;
      if ((i >> 2) & 1) G[3][tmp1] = 0;
      for (auto &x : group[i]){
         G[tmp1][tmp2] = x;
         tmp2++;
         if(tmp2 > 55){
            tmp2 -= 23;
            tmp1++;
            G[tmp1 - 1][tmp1] = 0;
         }
      }
      tmp1++;
   }
   REP(i, 22) G[i + 33][55] = 0;
   ll M = 0;
   REP(i, 56) REP(j, 56) M += (G[i][j] >= 0);
   cout << 56 <<' '<<  M << endl;
   REP(i, 56) REP(j, 56){
      if(G[i][j] >= 0){
         cout << i + 1 <<' ' <<  j + 1 << ' '<< G[i][j] << endl;
      }
   }
}
