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

const ll MAX_N = 50;
const ll MAX_X = 1e6;
const ll MAX_Y = 1e6;
const ll MAX_D = 1e6;

ll N, K;
ll X1[MAX_N], X2[MAX_N], Y1[MAX_N], Y2[MAX_N], D1[MAX_N], D2[MAX_N];
ll grid[MAX_N * 2 + 5][MAX_N * 2 + 5][MAX_N * 2 + 5];

vector<ll> compress(ll *x1, ll *x2){
    //x1, x2を座標圧縮した結果
    //ex: x1 = {10, 20, 30}, x2 = {60, 50, 40}なら
    //xs = {10, 20, 30 ,40, 50, 60}が返ってきて, 
    //x1 = {0, 1, 2}, x2 {5, 4, 3}となる
    //xsに0, 1e6（端点）を追加しておく

    vector<ll> xs;
    xs.pb(0);
    xs.pb(1e6);

    REP(i, N){
        xs.pb(x1[i]);
        xs.pb(x2[i]);
    }
    SORT(xs);
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    REP(i, N){
        x1[i] = find(ALL(xs), x1[i]) - xs.begin();
        x2[i] = find(ALL(xs), x2[i]) - xs.begin();
    }
    return xs;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //input
    cin >> N >> K;
    REP(i, N){
        cin >> X1[i] >> Y1[i] >> D1[i] >> X2[i] >> Y2[i] >> D2[i];
    }
    memset(grid, 0, sizeof(grid));
    vector<ll> X, Y, D;
    X = compress(X1, X2), Y = compress(Y1, Y2), D = compress(D1, D2);
    REP(i, N){
        FOR(x, X1[i], X2[i]){
            FOR(y, Y1[i], Y2[i]){
                FOR(d, D1[i], D2[i]){
                    grid[x][y][d]++;
                }
            }
        }
    }
    ll ans = 0;
    REP(i, X.size() - 1){
        REP(j, Y.size() - 1){
            REP(k, D.size() - 1){
                if(grid[i][j][k] >= K){
                    ans += (X[i + 1] - X[i]) * (Y[j + 1] - Y[j]) * (D[k + 1] - D[k]);
                }
            }
        }
    }
    cout << ans << endl;
}