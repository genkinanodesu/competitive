#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;
   typedef pair<ll, ll> P;

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

   int gcd(int a,int b){return b?gcd(b,a%b):a;};

   int dx[4]={1,0,-1,0};
   int dy[4]={0,1,0,-1};

int H, W, K;
vector<int> Fib = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};

ll f(ll x){
    if (x >= 0) return Fib[x];
    else return 1;
}
ll S[10][10] = {};
ll ans[101][10] = {};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> H >> W >> K;
    FOR(i, 1, W + 1){
        S[i][i] = f(i - 1) * f(W - i);
        S[i][i - 1] = f(i - 2) * f(W - i);
        S[i][i + 1] = f(i - 1) * f(W - i - 1);
    }
    ans[0][1] = 1;
    REP(k, H){
        FOR(i, 1, W + 1){
            ans[k + 1][i] = ans[k][i - 1] * S[i-1][i] + ans[k][i] * S[i][i] + ans[k][i+1] * S[i+1][i];
            ans[k+1][i] %= MOD;
        }
    }
    cout << ans[H][K] << endl;


    return 0;
}