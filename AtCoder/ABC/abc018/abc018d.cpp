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

ll n, m, p, q, r;
//a[i] = {(女子iがチョコを渡す男子, 幸福度)}
//b[i] = {(男子iがチョコをもらう女子, 幸福度)}
vector<vector<pair<ll, ll>>> a;
vector<vector<pair<ll, ll>>> b;

ll happiness( ll x);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> p >> q >> r;
    a.resize(n);
    b.resize(m);
    
    REP(i, r){
        ll xi, yi, zi; cin >> xi >> yi >> zi;
        a[xi - 1].pb(mp(yi - 1, zi));
        b[yi - 1].pb(mp(xi - 1, zi));
    }
    ll ans = 0;
    ll comb = (1 << p) - 1;
    while (comb < (1 << n)){
        chmax(ans, happiness(comb));
        ll x = comb & -comb, y = comb + x;
        comb = ((comb & ~y) / x >> 1) | y;
    }
    cout << ans << endl;
    return 0;
}

ll happiness(ll x){
    //女子p人の選び方x(nビットで表現)が与えられたときに、幸福度の最大を考える
    ll ans = 0;
    //h[i] = 男子iが旅行に参加したときに生まれる幸福度
    //すなわち、h[i] = sum _{b[i]とxの両方に含まれる女子j} (j, i)に対応する幸福度
    vector<ll> h(m, 0);
    REP(i, m){
        REP(j, b[i].size()){
            if ((x >> b[i][j].first) & 1){
                h[i] += b[i][j].second;
            }
        }
    }
    SORT(h);
    REVERSE(h);
    REP(i, q){
        ans += h[i];
    }
    return ans;
}