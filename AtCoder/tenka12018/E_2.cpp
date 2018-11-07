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

   int dx[8]={1,0,-1,0,1,0,-1,0};
   int dy[8]={0,1,0,-1,0,1,0,-1};

const ll MAX_H = 300, MAX_W = 300;
ll H, W;
bool grid[MAX_H + MAX_W][MAX_H + MAX_W] = {};

ll cum1[MAX_H + MAX_W][MAX_H + MAX_H] = {};
ll cum2[MAX_H + MAX_W][MAX_H + MAX_H] = {};

ll eq(){
    ll ans = 0;
    REP(i, H + W - 1){
        REP(j, H + W - 1){
            if (grid[i][j]){
                FOR(p, 1, H + W){
                    if (i + p < H + W - 1 && grid[i + p][j]){
                        if (j + p < H + W - 1){
                            ans += cum2[i + p][j + p] - cum2[i + 1][j + p];
                        }
                        if (j - p >= 0){
                            ans += cum2[i + p][j - p] - cum2[i + 1][j - p];
                        }
                    }
                    if (j + p < H + W - 1 && grid[i][j + p]){
                        if (i + p < H + W - 1){
                            ans += cum1[i + p][j + p] - cum1[i + p][j + 1];
                        }
                        if (i - p >= 0){
                            ans += cum1[i - p][j + p] - cum1[i - p][j + 1];
                        }
                    }
                }
            }
        }
    }
    return ans;
}

ll right_eq(){
    ll ans = 0;
    REP(i, H + W - 1){
        REP(j, H + W - 1){
            if(grid[i][j]){
                FOR(p, 1, H + W){
                    if (i + p < H + W - 1 && j + p < H + W - 1) ans += grid[i][j + p] * grid[i + p][j];
                    if (i + p < H + W - 1 && j - p >= 0) ans += grid[i][j - p] * grid[i + p][j];
                    if (i - p >= 0 && j + p < H + W - 1) ans += grid[i][j + p] * grid[i - p][j];
                    if (i - p >= 0 && j - p >= 0) ans += grid[i][j - p] * grid[i - p][j];
                }
            }
        }
    }
    return ans;
}
int main(){
    //input
    cin >> H >> W;
    REP(i, H){
        REP(j, W){
            char s;
            cin >> s;
            if (s == '#') grid[i + j][-i + j + H - 1] = true;
        }
    }
    //累積和は埋めておく
    REP(i, H + W - 1){
        REP(j, H + W - 1){
            cum1[i][j + 1] = cum1[i][j] + grid[i][j];
        }
    }
    REP(j, H + W - 1){
        REP(i, H + W - 1){
            cum2[i + 1][j] = cum2[i][j] + grid[i][j];
        }
    }

    ll ans = right_eq() + eq();
    cout << ans << endl;
}