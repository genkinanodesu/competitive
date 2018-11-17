#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;
   typedef pair<ll, ll> Pl;
   typedef pair<double, double> Pd;

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

const ll MAX_N = 1e12, MAX_M = 1e5;
ll N, N_, M;
ll p[MAX_M];
double a[MAX_M], b[MAX_M];

ll compress(ll *x){
    //xを座標圧縮し、その長さを返す
    vector<ll> xs;
    REP(i, M){
        xs.pb(x[i]);
    }
    SORT(xs);
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    REP(i, M){
        x[i] = lower_bound(ALL(xs), x[i]) - xs.begin();
    }
    return xs.size();
}

//Segment Tree
Pd dat[4 * MAX_M];
Pd monoid(Pd x, Pd y){
    //モノイド積
    //単位元は(1,0) 結合法則を満たす　非可換
    return mp(x.first * y.first, x.second * y.first + y.second);
}
void init(ll n){
    //初期化
    N_ = 1;
    while(N_ < n) N_ *= 2;
    REP(i, 2 * N_ - 1) dat[i] = mp(1.0, 0.0);
}
void update(ll i, Pd x){
    //i番目の要素(0-indexed)をxでupdate
    i += N_ - 1;
    dat[i] = x;
    while (i > 0){
        i = (i - 1) / 2;
        dat[i] = monoid(dat[2 * i + 1], dat[2 * i + 2]);
    }
}
Pd query(ll a, ll b, ll k, ll l, ll r){
    //[a, b)についてモノイド積を計算した結果を返す
    //外部からはquery(a, b, 0, 0, N_)として呼ぶ
    if (r <= a || b <= l) return mp(1.0, 0.0);
    if (a <= l && r <= b) return dat[k];
    else{
        Pd vl = query(a, b, k * 2 + 1, l, (l+r) / 2);
        Pd vr = query(a, b, k * 2 + 2, (l+r) / 2, r);
        return monoid(vl, vr);
    }
}

int main(){
    scanf("%lld%lld", &N, &M);
    REP(i, M){
        scanf("%lld%lf%lf", &p[i], &a[i], &b[i]);
    }
    double tako_max = 1.0, tako_min = 1.0;
    ll n = compress(p);
    init(n);
    REP(i, M){
        update(p[i], mp(a[i], b[i]));
        chmax(tako_max, dat[0].first + dat[0].second);
        chmin(tako_min, dat[0].first + dat[0].second);
    }
    printf("%f\n%f\n", tako_min, tako_max);
}