#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;
   typedef pair<ll, ll> P;

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

inline P U(P I, P J){
    //区間I, Jの共通部分を返す
    ll k1 = max(I.first, J.first);
    ll k2 = min(I.second, J.second);
    if (k1 < k2){
        return mp(k1, k2);
    }
    //共通部分が空のとき
    return mp(0, 0);
}

const ll MAX_M = 5010;
ll n, m, p, q, r;
vector<ll> x, y;
vector<P> I[MAX_M];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //input
    cin >> n >> m >> p >> q >> r;
    REP(i, m){
        ll xi, yi; cin >> xi >> yi;
        x.pb(xi); y.pb(yi);
    }

    //I[i]には、i回目のシャッフル後にr以上の数が並んでいる区間たちが入っている

    I[0].pb(mp(0, r));
    REP(i, m){
        //シャッフルi + 1回目の結果はI[i+1]に格納される
        REP(t, I[i].size()){
            P I1 = U(I[i][t], mp(0, x[i]));
            P I2 = U(I[i][t], mp(x[i], y[i]));
            P I3 = U(I[i][t], mp(y[i], n));

            /*シャッフルで、
            [0, xi) -> +n - xi
            [xi, yi) -> +n - xi - yi
            [yi, n) -> -yi
            とそれぞれ変化する。したがってI1, I2, I3がそれぞれ空でないときにこの操作をする
            1回のシャッフルで区間たちの数は2個しか増えないので、この操作は合計でO(m^2)回。
            */
            if (I1.first != I1.second) {
                I[i + 1].pb(mp(I1.first + n - x[i], I1.second + n - x[i]));
            }
            if (I2.first != I2.second){
                I[i + 1].pb(mp(I2.first + n - x[i] - y[i], I2.second + n - x[i] - y[i]));
            }
            if (I3.first != I3.second){
                I[i + 1].pb(mp(I3.first - y[i], I3.second - y[i]));
            }
        }
    }

    ll ans = 0;
    REP(i, I[m].size()){
        P K = U(I[m][i], mp(p - 1, q));
        ans += K.second - K.first;
    }
    cout << ans << endl;

    return 0;
}