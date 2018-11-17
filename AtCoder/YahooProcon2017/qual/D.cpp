#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;
   typedef pair<ll, ll> pii;

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

const ll MAX_Q = 1e5;
ll Q, K;
pii query[MAX_Q];
vector<ll> day;

void compress(){
    //座標圧縮
    //day[i]: 何らかのクエリを実行する日の日付
    //query[i].first ：その日付のdayでのindex
    //に変換される。
    //ex) query[].first = {1, 10, 100, 10, 1}なら、day[i] = {0, 1, 100} query[].first = {1, 2, 3, 2, 1}になる
    day.pb(0);
    REP(i, Q) day.pb(query[i].first);
    SORT(day);
    day.erase(unique(day.begin(), day.end()), day.end());
    REP(i, Q) query[i].first = lower_bound(day.begin(), day.end(), query[i].first) - day.begin();
}

pii monoid(pii x, pii y){
    return mp(max(x.first + y.second, y.first), x.second + y.second);
}

class SegmentTree{
    //i番目の要素：(Ai, Bi) X -> max(Ai, X + Bi)という変換
    //day[i]の前日に在庫がX個であったときにday[i]終了後の在庫を求める変換
    //この変換のmonoid積は(Ai, Bi) * (Aj, Bj) = (max(Ai + Bj, Aj), Bi + Bj)
    //単位元は(0, 0)

    private:
        ll n;
        vector<pii> dat;
    public:
        SegmentTree(ll N){
            n = 1;
            while (n < N) n *= 2;
            dat.resize(2 * n - 1, mp(0, 0));
        }
        void update(ll i, pii x){
            //Ai, Biをxに更新する
            i += n - 1;
            dat[i] = x;
            while(i > 0){
                i = (i - 1) / 2;
                dat[i] = monoid(dat[i * 2 + 1], dat[2 * i + 2]);
            }
        }
        void add(ll i , ll x){
            //(Ai, Bi) -> (Ai, Bi + x) : 
            //x > 0 : day[i]にx個生産する, x < 0 : day[i] に-x個出荷する
            pii y = dat[i + n - 1];
            y = mp(y.first, y.second + x);
            update(i, y);
        }
        pii prod(ll a, ll b, ll k, ll l, ll r){
            //区間[a, b)におけるモノイド積
            if (r <= a || b <= l) return mp(0, 0);
            if (a <= l && r <= b) return dat[k];
            else{
                pii pl = prod(a, b, k * 2 + 1, l, (l + r) / 2);
                pii pr = prod(a, b, k * 2 + 2, (l + r) / 2, r);
                return monoid(pl, pr);
            }
        }
        pii prod(ll a, ll b) {
            return prod(a, b, 0, 0, n);
        }
};

int main(){
    cin >> Q >> K;
    REP(i, Q){
        ll type; cin >> type;
        if (type == 1ll) cin >> query[i].first >> query[i].second;
        else {cin >> query[i].first; query[i].second = - INF;}
    }
    compress();
//    REP(i, day.size()) dump(day[i]);
//    REP(i, Q) {dump(query[i].first) dump(query[i].second)}
    SegmentTree seg(day.size());
    //生産
    FOR(i, 1, day.size()) seg.add(i, (day[i] - day[i - 1]) * K);
//    cout << "seg.n = " << seg.n << endl;
//    REP(i, seg.dat.size()) cout << "dat[i]=" << seg.dat[i].first << ' ' << seg.dat[i].second << endl;
    REP(i, Q){
//        REP(i, seg.n) cout << "dat[i]=" << seg.dat[i].first << ' ' << seg.dat[i].second << endl;
        if (query[i].second >= 0) {
            //出荷
            seg.add(query[i].first, - query[i].second);
        }
        else {
            //経理
            pii result = seg.prod(0, query[i].first + 1);
            //0 -> max(A, B)なので, max(result.first, result.second)が最も小さい在庫量
            cout << K * day[query[i].first] - max(result.first, result.second) << endl;
        }
    }

}