#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;
   typedef pair<ll, ll> P;

   const double EPS = (1e-7);
   const ll INF =(1e17);
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

const ll MAX_N = 1e5; ll MAX_A = 1e9;
ll N, N_;
ll A[MAX_N + 1];
ll B[MAX_N + 1];
ll C[MAX_N + 1];

ll dat[MAX_N * 4];

void init(){
    N_ = 1;
    while (N_ < N) N_ *= 2;
    REP(i, 2 * N_ - 1) dat[i] = - INF;
}

void update(ll i, ll x){
    //i番目の値をxに更新する
    i += N_ - 1;
    dat[i] = x;
    while (i > 0){
        i = (i - 1) / 2;
        dat[i] = max(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
}
ll query(ll a, ll b, ll k, ll l, ll r){
    //区間[a, b)の最大値を求める
    //kは節点の番号、[l, r)が対応する区間
    if (a == b) return 0;
    if (b <= l || r <= a) return - INF;
    if (a <= l && r <= b) return dat[k];
    else{
        ll vl = query(a, b, k * 2 + 1, l, (l + r)/2);
        ll vr = query(a, b, k * 2 + 2,  (l + r) /2 , r);
        return max(vl, vr);
    }
}

int main(){
    //input
    //A[i] = 本iの重さ (0-indexed)
    //B[j] = j番目にある本の番号 (0-indexed)
    //C[i] = 本iの場所
    //つまりC[B[j]] = j

    cin >> N;
    ll sum = 0;
    REP(i, N){
        cin >> A[i];
        sum += A[i];
    }
    REP(j, N){
        ll Bj; cin >> Bj;
        B[j] = Bj - 1;
        C[B[j]] = j;
    }
    init();
    REP(i, N_){
        update(i, 0);
    }
    REP(i, N){
        update(C[i], query(0, C[i], 0, 0, N_) + A[i]);
    }
    cout << 2 * (sum - query(0, N, 0, 0, N_)) << endl;
}