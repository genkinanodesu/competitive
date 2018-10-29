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

const ll MAX_W = 100000;
const ll MAX_H = 100000;
const ll MAX_N = 1000;

ll W, H, N;
ll X1[MAX_N], X2[MAX_N], Y1[MAX_N], Y2[MAX_N];

bool grid[MAX_N * 6][MAX_N * 6];


//x1, x2を座標圧縮, 圧縮した際の幅を返す
ll compress(ll *x1, ll *x2, ll w){
    vector<ll> xs;

    REP(i, N){
        FOR(d, -1, 1){
            ll tx1 = x1[i] + d, tx2 = x2[i] + d;
            if (0 <= tx1 && tx1 < w) xs.push_back(tx1);
            if (0 <= tx2 && tx2 < w) xs.push_back(tx2);
        }
    }
    SORT(xs);
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    REP(i, N){
        x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
        x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
    }
    return xs.size();
}
ll dfs(){
    //塗りつぶし
    memset(grid, 0, sizeof(grid));
    REP(i, N){
        FOR(x, X1[i], X2[i]){
            FOR(y, Y1[i], Y2[i]){
                grid[x][y] = true;
            }
        }
    }
    //領域を数える
    ll ans = 0;
    REP(x, W){
        REP(y, H){
            if (grid[x][y]) continue;
            ans++;
            
            //幅優先探索
            queue<pair<int, int>> que;
            que.push(mp(x, y));
            while (!que.empty()){
                ll sx = que.front().first, sy = que.front().second;
                que.pop();
                REP(i, 4){
                    ll tx = sx + dx[i], ty = sy + dy[i];
                    if(0 <= tx && tx < W && 0 <= ty && ty < H && !grid[tx][ty]){
                        que.push(mp(tx, ty));
                        grid[tx][ty] = true;
                    }
                }
            }
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> W >> H >> N;
    REP(i, N){
        cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
    }
    W = compress(X1, X2, W);
    H = compress(Y1, Y2, H);
    cout << dfs() << endl;
}