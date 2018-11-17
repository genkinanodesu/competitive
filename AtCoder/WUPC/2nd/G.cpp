#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;
   typedef pair<ll, ll> P;

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

class BIT{
    //1-index, A1, A2, ..., A_Mの更新および累積和をO(logM)で求める.
    //2分探索もできる.
    public:
        vector<ll> bit;
        ll M;

    BIT(ll M):
        //宣言と初期化
        bit(vector<ll>(M + 2, 0)), M(M) {}

    ll sum(ll i) {
        if (!i) return 0;
        return bit[i] + sum(i-(i&-i));
    }
    void add(ll i, ll x) {
        if (i > M) return;
        bit[i] += x;
        add(i+(i&-i), x);
    }
    ll lower_bound(ll x){
        //普通のlower_boundと同じ


        //解の範囲は(l, r]
        //sum(m) < x -> (m, r]
        //sum(m) >=x -> (l, m]
        ll l = 0, r = M + 1;
        while (r - l > 1){
            ll m = (l + r) / 2;
            if (sum(m) < x) l = m;
            else r = m;
        }
        return r;
    }
    ll upper_bound(ll x){
        //普通のupper_boundと同じ
        //解の範囲は(l, r]
        //sum(m) > x -> (l, m]
        //sum(m) <=x -> (m, r]

        ll l = 0, r = M + 1;
        while (r - l > 1){
            ll m = (l + r) / 2;
            if (sum(m) > x) r = m;
            else l = m;
        }
        return r;
    }
};

const ll MAX_N = 1e5, MAX_M = 1e5, MAX_H = 1e5;
ll N, M, H;
ll a[MAX_M + MAX_N] = {};
bool opr[MAX_M];
ll b[MAX_M];

int main(){
    cin >> N >> M >> H;
    BIT s(N + M);
    REP(i, N) {
        cin >> a[i];
        s.add(i + 1, a[i]);
    }
    REP(i, M){
        string op; cin >> op;
        (op == "add") ? opr[i] = 0 : opr[i] = 1;
        cin >> b[i];
    }
    REP(i, M){
        if (!opr[i]){
            s.add(i + N + 1, b[i]); 
        }
        else{
            ll lb = s.upper_bound(b[i] - H);
            ll ub = s.lower_bound(b[i] + H);
            if (lb == N + M + 1){
                cout << "miss" << endl;
            }
            else if (s.sum(ub) - s.sum(lb) == 0){
                cout << "go" << endl;
                ll t = s.sum(lb) - s.sum(lb - 1);
                s.add(lb, -t);
            }
            else {
                cout << "stop" << endl;
            }
        }
    }
}