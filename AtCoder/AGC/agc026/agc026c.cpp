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

ll N;
string S;

typedef pair<string, string> PS;

void solve(){
    //v1 = 前半n文字を(赤, 青)に割り振った文字列のペア
    //v2 = 紅斑n文字を(赤, 青)に割り振った文字列のペア　後半は後ろから読む
    vector<PS> v1, v2;
    REP(j, 1 << N){
        string s1_red, s1_blue, s2_red, s2_blue;
        REP(i, N){
            if ((j >> i) & 1){
                s1_red += S[i];
                s2_red += S[2 * N - 1 - i];
            }
            else {
                s1_blue += S[i];
                s2_blue += S[2 * N - 1 - i];
            }
        }
        v1.pb(mp(s1_red, s1_blue));
        v2.pb(mp(s2_blue, s2_red));
    }
    SORT(v1); SORT(v2);
    ll ans = 0;
    REP(i, v1.size()){
        ans += upper_bound(ALL(v2), v1[i]) - lower_bound(ALL(v2), v1[i]);
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //input
    cin >> N >> S;

    solve();

    return 0;
}