#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;
   typedef pair<ll, ll> P;

   const double EPS = (1e-7);
   const ll INF =(1e15);
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

   ll gcd(ll a,ll b){return b?gcd(b,a%b):a;};

   ll dx[4]={1,0,-1,0};
   ll dy[4]={0,1,0,-1};

const ll MAX_N = 1e5;
const ll MAX_Q = 1e5;

ll n, q;
ll com[MAX_Q], x[MAX_Q], y[MAX_Q];
ll dat[4 * MAX_N - 1];

//初期化
void init(ll n_){
    //要素数を2のべき乗にする
    n = 1;
    while (n < n_) n *= 2;

    //すべての値を2^31 - 1に
    REP(i, 2 * n - 1){
        dat[i] = ((1ull << 31) - 1);
    }
}

//A[i] を xに変更する
void update(ll i, ll x){
    i += n - 1;
    dat[i] = x;

    while (i > 0){
        i = (i - 1) / 2;
        dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
}


//[a,b)の最小値を出力する
//k = 節点の番号 [l, r)は対応する区間
//したがって[a, b)の最小値はquery(a, b, 0, 0, n)として呼ぶ
ll query(ll a, ll b, ll k, ll l, ll r){
    //[a, b)と[l, r)が交差しなければINF;
    if (r <= a || b <= l) return INF;

    //[a, b)が[l, r)を完全に含んでいれば、節点kが持つ値
    if (a <= l && r <= b) return dat[k];
    else{
        //その他の場合は, 2つの子の最小値
        ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return min(vl, vr);
    }    
}

int main(){

    //input
    cin >> n >> q;
    REP(i, q){
        cin >> com[i] >> x[i] >> y[i];
    }
    init(n);
    REP(i, q){
        if (com[i] == 0) update(x[i], y[i]);
        else cout << query(x[i], y[i]+1, 0, 0, n) << endl;
    }
    return 0;
}