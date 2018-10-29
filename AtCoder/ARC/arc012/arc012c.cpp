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

//n路盤, m目並べ
const int n = 19;
const int m = 5;

//入力はa[i]j]に入れる
vector<vector<int>> a(n, vector<int>(n));

const int black = 1;
const int white = -1;

bool win(vector<vector<int>>grid, int color);
bool check(vector<vector<int>> grid);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //input
    REP(i, n){
        string s; cin >> s;
        REP(j, n){
            if (s[j] == 'o') a[i][j] = 1;
            else if (s[j] == 'x') a[i][j] = -1;
            else a[i][j] = 0;
        }
    }
    if (check(a)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

bool win(vector<vector<int>>grid, int color){
    //盤面gridにおいて色color (black, white)が勝利しているか？
    REP(i, n){
        REP(j, n){
            if (grid[i][j] == color){
                bool flag1 = true, flag2 = true, flag3 = true, flag4 = true;
                REP(k, m){
                    flag1 *= ((i + k < n) && (grid[i + k][j] == color));
                    flag2 *= flag2 && ((j + k < n) && (grid[i][j + k] == color));
                    flag3 *= flag3 && ((i + k < n) && (j + k < n) && (grid[i + k][j + k] == color));
                    flag4 *= flag4 && ((i - k >= 0) && (j + k < n) && (grid[i - k][j + k] == color));
                }
                if (flag1 || flag2 || flag3 || flag4) return true;
            }
        }
    }
    return false;
}

bool check(vector<vector<int>> grid){
    //gridが五目並べの盤面としてありうるかをチェックする
    int b = 0, w = 0;
    REP(i, n){
        REP(j, n){
            if (grid[i][j] == 1) b += 1;
            else if (grid[i][j] == -1) w += 1;
        }
    }
    if (b == w + 1){
        //黒が置き終わった後の盤面
        //白が勝利していない　かつ　（黒が勝利してない　or 1個取り除くと黒が勝利していない）ならばYES それ以外はNO
        
        //白が勝利していたらfalse
        if (win(grid, white)) return false;
        //白が勝利していないとして
        else{
            //黒が勝利していなければtrue
            if (!win(grid, black)) return true;

            //黒を1個取り除いて黒が勝利していなければtrue
            REP(i, n){
                REP(j, n){
                    if (grid[i][j] == 1){
                        vector<vector<int>> grid_prev = grid;
                        grid_prev[i][j] = 0;
                        if (!win(grid_prev, black)) return true;
                    }
                }
            }
        }
        return false;
    }
    else if (b == w){
        //白が置き終わった後の盤面
        //黒が勝利してない　かつ　（白が勝利していない or 1個取り除くと白が勝利していない）　ならYes, それ以外ならNo

        //黒が勝利していたらfalse
        if (win(grid, black)) return false;
        //黒が勝利していないとして
        else{
            //白が勝利していなかればtrue
            if (!win(grid, white)) return true;

            //白を1個取り除いて白が勝利していなければtrue
            REP(i, n){
                REP(j, n){
                    if (grid[i][j] == -1){
                        vector<vector<int>> grid_prev = grid;
                        grid_prev[i][j] = 0;
                        if (!win(grid_prev, white)) return true;
                    }
                }
            }
        }
        return false;
    }
    else return false;
}

