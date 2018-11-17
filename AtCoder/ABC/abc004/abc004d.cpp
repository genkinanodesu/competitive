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

//部分点用　座標圧縮するときは書き換える
const ll MAX_W = 1e6;
const ll MAX_H = 1e6;
const ll MAX_N = 30;
ll W, H;
ll N;
ll X[MAX_N + 5], Y[MAX_N + 5]; // 座標圧縮後の座標
vector<ll> Xc, Yc; // 座標圧縮前の座標

//dp[x1][x2][y1][y2] = [x1, x2) * [y1, y2)から得られる金塊量の最大値
//座標圧縮後の座標を与える
ll dp[MAX_N + 5][MAX_N + 5][MAX_N + 5][MAX_N + 5];

vector<ll> compress(ll *x){
    //xを座標圧縮, 座圧前の座標をxsとして返す
    vector<ll> xs;
    REP(i, N + 2){
        xs.pb(x[i]);
    }
    SORT(xs);
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    REP(i, N + 2){
        x[i] = find(ALL(xs), x[i]) - xs.begin();
    }
    return xs;
}

ll gold(ll x1, ll x2, ll y1, ll y2){
    //(x1, x2) * (y1, y2)から得られる金塊量の最大値
    //ただしx1, x2, y1, y2はそれぞれ座標圧縮後のインデックス
    //メモ化dpで
    if (dp[x1][x2][y1][y2] >= 0) return dp[x1][x2][y1][y2];
    else if (x1 >= x2 || y1 >= y2){
        dp[x1][x2][y1][y2] = 0;
        return 0;
    }
    else {
        ll ans = - INF;
        REP(i, N){
            if (x1 < X[i] && X[i] < x2 && y1 < Y[i] && Y[i] < y2){
                ll temp = Xc[x2] - Xc[x1] + Yc[y2] - Yc[y1] - 3
                + gold(x1, X[i], y1, Y[i]) 
                + gold(x1, X[i], Y[i], y2) 
                + gold(X[i], x2, y1, Y[i]) 
                + gold(X[i], x2, Y[i], y2);
                chmax(ans, temp);
            }
        }
        dp[x1][x2][y1][y2] = max((ll) 0, ans);
        return max((ll)0, ans);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //input
    cin >> W >> H >> N;
    REP(i, N){
        cin >> X[i] >> Y[i];
    }
    X[N] = 0; X[N + 1] = W + 1;
    Y[N] = 0; Y[N + 1] = H + 1;
    //-INFで初期化
    REP(x1, MAX_N + 5){
        REP(x2, MAX_N + 5){
            REP(y1, MAX_N + 5){
                REP(y2, MAX_N + 5){
                    dp[x1][x2][y1][y2] = - INF;
                }
            }
        }
    }
    Xc = compress(X);
    Yc = compress(Y);
    cout << gold(0, Xc.size() - 1, 0, Yc.size() - 1) << endl;
}