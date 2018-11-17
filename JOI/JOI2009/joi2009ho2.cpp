#include <bits/stdc++.h>
using namespace std;

/*
templates for competitive programming
type long long -> type ll 
define constants : EPS, INF, MOD, PI
define macros : REP, FOR, ALL, SORT, REVERSE
define number theory functions: qp(a, b), qp(a, b, mo), gcd(a, b)
define dx, dy
*/
   typedef long long unsigned int ll;

   const double EPS = (1e-7);
   const int INF =(1e9);
   const double PI = (acos(-1));
   const int MOD = (int(1e9) + 7);

   #define REP(i, n) for(int i = 0; i < (int)(n); i++)
   #define FOR(i, a, b) for (int i = (a); i < (b); i++)
   #define ALL(x) (x).begin(),(x).end()
   #define SORT(x) sort((x).begin(), (x).end())
   #define REVERSE(x) reverse((x).begin(), (x).end())
   #define SZ(x) ((int)(x).size())


   #define dump(x) cerr<< #x << "= " << (x) << endl;

   int gcd(int a,int b){return b?gcd(b,a%b):a;};

   int dx[4]={1,0,-1,0};
   int dy[4]={0,1,0,-1};



const int MAX_n = 100000;
const int MAX_m = 10000;
const int MAX_d = pow(10, 9);
int d, n, m;
int s[MAX_n + 1];
int k[MAX_m];

int bin_1(int k) {
    // k以下の範囲で最もkに近い店舗の番号
    return int (upper_bound(s, s + n + 1, k) - s - 1);
}
int bin_2(int k){
    //kより大きい座標の範囲で最もkに近い店舗の番号
    return int (upper_bound(s, s + n + 1, k) - s);
}

int main() {
    /*
    d: 全周 <= 10 ** 9
    n: 店舗数 <= 10 ** 5
    m: 配達先 <= 10 ** 4
    s[i] = 店舗iの座標　ただしs[i] = 0, s[n] = dとする
    k[i] = 配達先iの座標
    */
   cin.tie(0);
   ios::sync_with_stdio(false);
   cin >> d >> n >> m;
   s[0] = 0, s[n] = d;
   REP(i, n-1){
       cin >> s[i + 1];
   }
   REP(i, m){
       cin >> k[i];
   }
   sort(s, s + n + 1);
   sort(k, k + m);
   int ans = 0;
   REP(i, m){
       int d1, d2;
       d1 = k[i] - s[bin_1(k[i])];
       d2 = s[bin_2(k[i])] - k[i];
       ans += min(d1, d2);
   }
   cout << ans << endl;
}