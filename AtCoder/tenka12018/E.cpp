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
bool grid[MAX_H][MAX_W];

bool coin(ll x, ll y){
    //(x,y)にコインがあるかを判定
    if (0 <= x && x < H && 0 <= y && y < W && grid[x][y]) return true;
    else return false;
}

/*累積和を持っておく
coin(x, k - x) = cum1[k + H + W][x + H + W + 1] - cum1[k + H + W][x + H + W];
coin(x, x - k) = cum2[k + (H + W)][x + H + W + 1] - cum2[k + (H + W)][x + H + W];
*/
ll cum1[3 * (MAX_H + MAX_W + 1)][2 * (MAX_H + MAX_W + 1)] = {};
ll cum2[3 * (MAX_H + MAX_W + 1)][2 * (MAX_H + MAX_W + 1)] = {};
void f(){
    REP(k, 3 * (H + W) + 1){
        REP(x, 2 * (H + W) + 1){
            cum1[k][x + 1] = cum1[k][x] + coin(x - (H + W), k - x);
            cum2[k][x + 1] = cum2[k][x] + coin(x - (H + W), x - k);
        }
    }
}

ll diff(ll x1, ll y1, ll x2, ll y2){
    //(x1, y1)と(x2, y2)の間（端点含まない）の間に何個あるか
    if (x1 > x2) return diff(x2, y2, x1, y1);
    else if (x1 == x2) return 0;
    else{
        if(x1 + y1 == x2 + y2){
            return cum1[x1 + y1 + H + W][x2 + H + W] - cum1[x1 + y1 + H + W][x1 + H + W + 1];
        }
        if(x1 - y1 == x2 - y2){
            return cum2[x1 - y1 + H + W][x2 + H + W] - cum2[x1 - y1 + H + W][x1 + H + W + 1];
        }
    }
    return 0;
}

ll eq(){
    /*
    (i + dx[k] * p, j + dy[k] * p)
    (i + dx[k + 1] * p, j + dy[k + 1] * p)
    (i + dx[k + 2] * x + dx[k + 3] * (p-x), j + dy[k + 2] * x + dy[k + 3] * (p-x)) (0<x<p)
    を数え上げる
    */
   ll ans = 0;
   REP(i, H){
       REP(j, W){
           FOR(p, 1, min(H, W) + 1){
               REP(k, 4){
                   if (coin(i + dx[k] * p, j + dy[k] * p) && coin(i + dx[k + 1] * p, j + dy[k + 1] * p)){
                       ans += diff(i + dx[k + 2] * p, j + dy[k + 2] * p, i + dx[k + 3] * p, j + dy[k + 3] * p);
                   }
               }
           }
       }
   }
   return ans;
}
ll right_eq(){
    //直角二等辺三角形は別に数える
    ll ans = 0;
    REP(i, H){
        REP(j, W){
            FOR(p, 1, min(H, W)){
                if(coin(i+p,j) && coin(i, j+p) && coin(i,j-p)) ans++;
                if(coin(i+p,j) && coin(i, j+p) && coin(i-p,j)) ans++;
                if(coin(i+p,j) && coin(i, j-p) && coin(i-p,j)) ans++;
                if(coin(i-p,j) && coin(i, j+p) && coin(i,j-p)) ans++;
            }
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //input
    cin >> H >> W;
    REP(i, H){
        REP(j, W){
            char s;
            cin >> s;
            (s == '#') ? grid[i][j] = true: grid[i][j] = false;
        }
    }
    //累積和は埋めておく
    f();
    ll ans = right_eq() + eq();
    cout << ans << endl;
}