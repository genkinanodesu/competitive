#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;
   typedef pair<ll, ll> Pii;
   typedef vector<ll> Vi;
   typedef vector<Vi> VVi;

   const double EPS = (1e-7);
   const ll INF =(1e13);
   const double PI = (acos(-1));
   const ll MOD = (ll)998244353;

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

//functions
   ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
   ll pow(ll a, ll b){if (b == 0) return 1; else if (b % 2 == 0) return pow(a * a, b / 2); else return pow(a * a, b / 2) * a;}
   ll pow(ll a, ll b, ll m){if (b == 0) return 1; else if (a == 0) return 0; else if (b % 2 == 0) return (pow((a * a) % m, b / 2, m) % m); else return (pow((a * a) % m, b / 2, m) * a) % m;}
   ll residue(ll a, ll m){return ((a % m) + m) % m;};

   ll dx[4]={1,0,-1,0};
   ll dy[4]={0,1,0,-1};

//与えられたF2上の行列をAとして、(1 << (M * N - rank(A) - 1)) * ((1 << rank(A)) - 1 )が答え.
const ll MAX_M = 300, MAX_N = 300;
ll N, M;
ll a[MAX_N][MAX_M];

ll rnk(){
   ll r = 0;
   ll i = 0, j = 0;
   while(i < N && j < M){
      //a[i][j] = 0のときは、k = i + 1, ..., N - 1 からa[k][j] != 0なるkを探してきて, i行目とk行目を入れ替える
      if(!a[i][j]){
         FOR(k, i + 1, N){
            if(a[k][j]){
               REP(l, M){
                  swap(a[i][l], a[k][l]);
               }
               break;
            }
         }
      }
      //入れ替えを行ってもa[i][j] = 0のとき（つまりj列目はすべて0のとき)はj列目をスキップ j+1列目にトライ
      if(!a[i][j]){j++; continue;}
      r++;
      //k = i+1,...,N-1行目についてi行目を引く
      FOR(k, i + 1, N){
         ll c = a[k][j];
         REP(l, M){
            a[k][l] += c * a[i][l];
            a[k][l] %= 2;
         }
      }
      i++; j++;
   }
   return r;
}

int main(){
   cin >> N >> M;
   REP(i, N) REP(j, M) cin >> a[i][j];
   ll r = rnk();
/*
   cout << endl;
   REP(i, N){
      REP(j, M){
         if(j) {cout << " ";}
         cout << a[i][j];
      }
      cout << endl;
   }
   cout << "rnk = " << r << endl;
*/
   cout << residue(pow(2ll, N + M - 1, MOD) - pow(2ll, N + M - 1 - r, MOD), MOD) << endl;

}
