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

   ll gcd(ll a, ll b){return b?gcd(b,a%b):a;};

   ll pow(ll a, ll b){ if (b == 0) {return 1;} else if ( b % 2 == 0) {return pow(a * a, b / 2);} else {return a * pow(a * a, b / 2);}}
   
   ll dx[4]={1,0,-1,0};
   ll dy[4]={0,1,0,-1};

const ll MAX_N = 2e5, MAX_X = 15;
ll N;
ll A[MAX_N]; //0-indexed
ll dp_pos[MAX_N][MAX_X + 1];
ll dp_neg[MAX_N][MAX_X + 1];

ll positive(ll l, ll x){
   //A_l, ..., A_N-1に対し、A_lに*4をx回するという条件下で*4倍を合計何回すれば単調増加列を作れるか？
   if (l >= N || l < 0) return 0;
   else if (x > MAX_X) return (positive(l, MAX_X) + (x - MAX_X) * (N - l));
   else if (dp_pos[l][x] >= 0) return dp_pos[l][x];
   else{
      if (l == N - 1) {
         dp_pos[l][x] = x;
         return x;
      }
      else{
         ll k = 0;
         ll tmp1 = (A[l] << (2 * x));
         ll tmp2 = A[l + 1];
         if (tmp1 > 1e9) {
            dp_pos[l][x] = positive(l, x - 1) + N - l;
         }
         else{
            while (tmp2 < tmp1){
               tmp2 *= 4;
               k ++;
            }
         dp_pos[l][x] = positive(l + 1, k) + x;
         }
         return dp_pos[l][x];     
      }
   }
}

ll negative(ll l, ll x){
   /*
   A0, A1, ..., A_lに対し, A_lに*4をx回したときに合計*4を何回すれば単調減少列を作れるか？
   */
   if (l >= N || l < 0) return 0;
   else if (x > MAX_X) return (negative(l, MAX_X) + (x - MAX_X) * (l + 1));
   else if (dp_neg[l][x] >= 0) return dp_neg[l][x];
   else{
      if (l == 0) {
         dp_neg[l][x] = x;
         return x;
      }
      else{
         ll k = 0;
         ll tmp1 = (A[l] << (2 * x));
         ll tmp2 = A[l - 1];
         if (tmp1 > 1e9){
            dp_neg[l][x] = negative(l, x - 1) + l + 1;
         }
         else{
            while (tmp2 < tmp1){
               tmp2 *= 4;
               k ++;
            }
            dp_neg[l][x] = negative(l - 1, k) + x;
         }
         return dp_neg[l][x];     
      }
   }
}

int main(){
   //input
   cin >> N;
   REP(i, N){
      cin >> A[i];
   }
   //init DPtable with -1
   REP(l, MAX_N){
      REP(x, MAX_X + 1){
         dp_pos[l][x] = -1;
         dp_neg[l][x] = -1;
      }
   }
   /*
   REP(l, N){
      REP(x, 4){
         printf("positive(%lld, %lld) = %lld\n", l, x, positive(l,x));
         printf("negative(%lld, %lld) = %lld\n", l, x, negative(l,x));
      }
   }
   */
   ll ans = INF;
   REP(i, N + 1){
      ll tmp = positive(i, 0) * 2 + negative(i - 1, 0) * 2 + i;
      chmin(ans, tmp);
   }
   cout << ans << endl;
}