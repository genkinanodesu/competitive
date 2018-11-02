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

const ll MAX_N = 32;
ll N, X;
ll w[MAX_N];

void solve(){
    ll N2 = N / 2;
    vector<ll> s1, s2;
    REP(i, 1 << N2){
        ll sw = 0;
        REP(j, N2){
            if ((i >> j) & 1){
                sw += w[j];
            }
        }
        if (sw <= X) s1.pb(sw);
    }
    REP(i, 1 << (N - N2)){
        ll sw = 0;
        REP(j, N - N2){
            if ((i >> j) & 1){
                sw += w[j + N2];
            }
        }
        if(sw <= X) s2.pb(sw);
    }
    SORT(s1); SORT(s2);
    ll ans = 0;
    REP(i, s1.size()){
        ans += upper_bound(s2.begin(), s2.end(), X - s1[i]) - lower_bound(s2.begin(), s2.end(), X - s1[i]) ;
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //input
    cin >> N >> X;
    REP(i, N){
        cin >> w[i];
    }
    solve();
    
    return 0;
}