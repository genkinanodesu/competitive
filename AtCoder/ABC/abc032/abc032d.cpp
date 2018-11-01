#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;
   typedef pair<ll, ll> P;

   const double EPS = (1e-7);
   const ll INF =ll(1e15);
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

ll N, W;
vector<ll> v, w;

ll kn1(){
    //N<=30のとき：半分全列挙
    //s1 = {sw_j, sv_j} jは{0,1,...,N'=N/2}の部分集合, sw_j, sv_jはそれぞれwi, viをjの要素について和を取る
    //s2 = {sw_j, sv_j} jは{N'+1,2,...,N - 1}の部分集合, sw_j, sv_jはそれぞれwi, viをjの要素について和を取る
    //テクニカルな話：valueを-1倍しておくことでソートすればswの小さい順、かつ同じswではsvの大きい順に並ぶ
    ll N2 = N / 2;
    vector<P> s1, s2;
    REP(j, 1 << N2){
        ll sw = 0, sv = 0;
        REP(i, N2){
            if ((j >> i) & 1) sw += w[i], sv += - v[i];
        }
        if (sw <= W) s1.pb(mp(sw, sv));
    }
    REP(j, 1 << (N - N2)){
        ll sw = 0, sv = 0;
        REP(i, N - N2){
            if ((j >> i) & 1) sw += w[i + N2], sv += - v[i + N2];
        }
        if (sw <= W) s2.pb(mp(sw, sv));
    }
    SORT(s1); SORT(s2);

    //s1, s2からそれぞれwj <= wj' かつ vj >= vj'となるような要素を取り除きたい
    //いまs1, s2は(w, -v)によってソートされているので、前から順番にvjが大きくなっていくようにとればよい

    vector<P> s1_sort, s2_sort;
    s1_sort.pb(s1[0]); s2_sort.pb(s2[0]);
    REP(j, s1.size()){
        if (s1[j].second < s1_sort.back().second) s1_sort.pb(s1[j]);
    }
    REP(j, s2.size()){
        if (s2[j].second < s2_sort.back().second) s2_sort.pb(s2[j]);
    }

    //s1_sortの各要素に対して、s2_sortから2分探索

    ll ans = 0;
    REP(i, s1_sort.size()){
        ll j = lower_bound(ALL(s2_sort), mp(W - s1_sort[i].first, INF)) - s2_sort.begin() - 1;
        chmin(ans, s1_sort[i].second + s2_sort[j].second);
    }
    return -ans;
}

ll kn2(){
    //普通のナップサックDP 重さで 
    ll w_sum = accumulate(w.begin(), w.end(), 0);
    if (W > w_sum) return accumulate(v.begin(), v.end(), 0);
    else{
        ll dp[N + 1][W + 1] = {};
        REP(i, N){
            REP(j, W + 1){
                if (j >= w[i]) dp[i + 1][j] = max(dp[i][j - w[i]] + v[i], dp[i][j]);
                else dp[i + 1][j] = dp[i][j];
            }
        }
        return dp[N][W];
    }

}
ll kn3(){
    //普通のナップサックDP 価値で

    ll v_sum = accumulate(v.begin(), v.end(), 0);
    ll dp[N + 1][v_sum + 1];

    //dpテーブルを初期化
    REP(i, N + 1){
        dp[i][0] = 0;
        FOR(j, 1, v_sum + 1){
            dp[i][j] = INF;
        }
    }

    REP(i, N){
        REP(j, v_sum + 1){
            dp[i + 1][j] = min(dp[i][j], dp[i][max((ll)0, j - v[i])] + w[i]);
        }
    }
    //dp[N]を2分探索しても全体での計算量オーダーは変わらない。

    REP(j, v_sum + 1){
        if (dp[N][j] > W) return j - 1;
    }
    return INF;    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> W;
    ll W_MAX = 0, V_MAX = 0;
    REP(i, N){
        ll vi, wi; cin >> vi >> wi;
        v.pb(vi); w.pb(wi);
        chmax(W_MAX, wi);
        chmax(V_MAX, vi);
    }
    if (N <= 30) cout << kn1() << endl;
    else if (W_MAX <= 1000) cout << kn2() << endl;
    else if (V_MAX <= 1000) cout << kn3() << endl;
}