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

//隣接リストEによる表現：E[i] = 頂点iに隣接する頂点たち　頂点は0-basedで記録
const ll MAX_N = 40;
ll N, M, N2;
vector<ll> E[MAX_N];

vector<ll> dp1, dp2;

void MIS1(){
    /*
    S1 = {0, 1, ..., N/2 -1}の部分集合T1（N/2ビットで表現）に対して
    S1の中での最大独立集合（Maximum Independent Set: MIS)の要素数を求める
    dp[T1] = max_{i in T1} (dp[T \ (i, E[i])] + 1)
    */
   REP(T1, 1 << N2){
       dp1[T1] = 0;
       REP(i, N2){
           if ((T1 >> i) & 1){
            ll T = T1 & ~(1 << i);
            REP(j, E[i].size()){
                if (E[i][j] < N2){
                    T &= ~(1 << E[i][j]);
                }
            }
           chmax(dp1[T1], dp1[T] + 1);
           }
       }
   }
}
void MIS2(){
    /*同じことをS2 = S \ S1に対してやる*/
    REP(T2, 1 << (N - N2)){
        dp2[T2] = 0;
        REP(i, N - N2){
            if ((T2 >> i) & 1){
                ll T = T2 & ~(1 << i);
                REP(j, E[i + N2].size()){
                    if (E[i + N2][j] >= N2){
                        T &= ~(1 << (E[i + N2][j] - N2));
                    }
                }
                chmax(dp2[T2], dp2[T] + 1);
            }
        }
    }
}

void solve(){
    ll ans = 0;
    REP(T1, 1 << N2){
        if (dp1[T1] == __builtin_popcount(T1)){
            ll T2 = (1 << (N - N2)) - 1;
            REP(i, N2){
                REP(j, E[i].size()){
                    if (((T1 >> i) & 1) && E[i][j] >= N2){
                        T2 &= ~ (1 << (E[i][j] - N2));
                    }
                }
            }
            chmax(ans, dp1[T1] + dp2[T2]);
        }
    }
    cout << ans << endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //input
    cin >> N >> M;
    REP(i, M){
        ll ai, bi;
        cin >> ai >> bi;
        E[ai - 1].pb(bi - 1);
        E[bi - 1].pb(ai - 1);
    }
    N2 = N / 2;
    dp1.resize(1 << N2); dp2.resize(1 << (N - N2));
    MIS1(); MIS2();
    solve();
    return 0;
}