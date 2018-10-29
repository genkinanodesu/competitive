#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;

   const double EPS = (1e-7);
   const ll INF =(1e9);
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

   int gcd(int a,int b){return b?gcd(b,a%b):a;};

   int dx[4]={1,0,-1,0};
   int dy[4]={0,1,0,-1};

ll r, c;
const ll max_r = 10;
const ll max_c = 10000;
ll a[max_r][max_c];

ll senbei(ll x);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //input
    cin >> r >> c;
    REP(i, r){
        REP(j, c){
            cin >> a[i][j];
        }
    }
    ll ans = 0;
    REP(x, 1 << r){
        chmax(ans, senbei(x));
    }
    cout << ans << endl;
}

ll senbei(ll x){
    //r行のひっくり返し方x (rビットで表現)が与えられたときに、表を向いたせんべいの最大値を求める
    ll ans = 0;
    ll b[max_r][max_c];
    memcpy(b, a, sizeof(a));
    REP(i, r){
        REP(j, c){
            b[i][j] = (b[i][j] + (x >> i)) % 2;
        }
    }
    REP(j, c){
        ll temp = 0;
        REP(i, r){
            temp += b[i][j];
        }
        ans += max(temp, r - temp);
    }
    return ans;
}