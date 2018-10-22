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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //input
    ll h, w; cin >> h >> w;
    ll a[h][w];
    ll S = 0;
    REP(i, h){
        REP(j, w){
            cin >> a[i][j];
            S = (S + a[i][j]) % 2;
        }
    }
    
    ll p[h];
    ll q[w];
    //p[i] = sum(0 <= k < w) b[i][k] + S
    //q[j] = sum(0 <= k < h) b[k][j] + S
    //bij = aij + pi + qj + 1
    REP(i, h){
        p[i] = 0; //0で初期化
        REP(k, w){
            p[i] += a[i][k];
        }
        p[i] += S;
        p[i] %= 2;
    }
    REP(j, w){
        q[j] = 0; //0で初期化
        REP(k, h){
            q[j] += a[k][j];
        }
        q[j] += S;
        q[j] %= 2;
    }

    ll b[h][w];
    REP(i, h){
        REP(j, w){
            b[i][j] = (a[i][j] + p[i] + q[j] + 1) % 2;
            cout << b[i][j];
            if (j!= w - 1){
                cout << ' ';
            }
        }
    cout << endl;
    }
}