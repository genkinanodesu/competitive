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
    public:
        vector<ll> bit;
        ll M;

    BIT(ll M):
        //宣言と初期化
        bit(vector<ll>(M+1, 0)), M(M) {}

    ll sum(ll i) {
        if (!i) return 0;
        return bit[i] + sum(i-(i&-i));
    }

    void add(ll i, ll x) {
        if (i > M) return;
        bit[i] += x;
        add(i+(i&-i), x);
    }
};


const ll MAX_N = 3e5, MAX_A = 1e5, MAX_B = 1e5;
ll N;
P bug[MAX_N];
BIT s0, s1;

//微生物数をk以上にすることができるか？
bool P(ll k);

int main(){
    scanf("%lld", &N);
    //s0はx以下のaiの個数を, s1はx以下のaiの総和を持つ
    s0 = BIT(N); s1 = BIT(N);

    REP(i, N){
        scanf("%lld%lld", &bug[i].first, &bug[i].second);
        s0.add(bug[i].first, 1);
        s1.add(bug[i].first, bug[i].first);
    }
    SORT(bug, bug + N, [](const P x, const P y,){return x.second < y.second;});
    ll k_min = 0, k_max = MAX_N + 1;
    //解は[k_min, k_max)の間
    while (k_max - k_min > 1){
        k_mid = (k_min + k_max) / 2;
        if(P(k_mid)) k_min = k_mid;
        else k_max = k_mid;
    }
    printf("%lld", k_min);
}

bool P(ll k){
    //微生物数をk以上にすることができるか？
}