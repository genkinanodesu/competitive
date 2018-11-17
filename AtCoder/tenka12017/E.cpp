#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;
   typedef pair<ll, ll> P;
   #define double long double

   const double EPS = (1e-10);
   const double INF =(1e9);
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

class BIT{
    //index : 1-based
    public:
        vector<ll> bit;
        ll M;

        BIT(ll M):
            bit(vector<ll>(M + 1, 0)), M(M) {}
        ll sum(ll i){
            ll s = 0;
            while (i > 0) {
                s += bit[i];
                i -= i & (-i);
            }
            return s;
        }

        void add(ll i, ll x){
            while (i <= M){
                bit[i] += x;
                i += i & -i;
            }
        }
};  

const ll MAX_N = 4e4;
ll N;
struct line{
    double A, B, C;
    double grad1() {return - (A / B);} //y = px + qの形に書いた時の傾き
    double grad2() {return - (B / A);} // x = py + qの形に書いた時の傾き
};
struct line L[MAX_N];

vector<double> at_x(double x){
    //values Y at X = x
    vector<double> v;
    REP(i, N) v.pb((L[i].C - L[i].A * x) / L[i].B);
    return v;
}

vector<double> at_y(double y){
    //values X at Y = y
    vector<double> v;
    REP(i, N) v.pb((L[i].C - L[i].B * y) / L[i].A);
    return v;
}


ll inversion(vector<double> x){
    //vector xの転倒数を求める
    BIT t(N);
    vector<pair<double, ll>> y;
    ll ans = 0;
    REP(i, x.size()){
        y.pb(mp(x[i], i));        
    }
    SORT(y);
    REP(i, x.size()){
        ans += y[i].second - t.sum(y[i].second + 1);
        t.add(y[i].second + 1, 1);
    }
    return ans;
}


int main(){
    scanf("%lld", &N);
    ll M = N * (N - 1) / 2;
    REP(i, N) {
        scanf("%Lf%Lf%Lf", &L[i].A, &L[i].B, &L[i].C);
    }
    sort(L, L + N, 
    [](line p, line q) {
        return p.grad1() < q.grad1();
        }); //x = + INFでの値でソート
    double x_min = - INF, x_max = INF;
    while (x_max - x_min > EPS){
        double xmid = (x_max + x_min) / 2;
        if (inversion(at_x(xmid)) <= M / 2) x_max = xmid;
        else x_min = xmid;
    }

    sort(L, L + N, 
    [](line p, line q) {
        return p.grad2() < q.grad2();
        }); // y = + INF での値でソート
    double y_min = - INF, y_max = INF;
    while (y_max - y_min > EPS){
        double ymid = (y_max + y_min) / 2;
        if (inversion(at_y(ymid)) <= M / 2) y_max = ymid;
        else y_min = ymid;
    }
    printf("%.10Lf %.10Lf\n", x_min, y_min);
}
