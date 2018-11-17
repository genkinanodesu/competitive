#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;

   const double EPS = (1e-7);
   const ll INF =(1e9);
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

const ll MAX_N = 1e5;
ll N;
ll A[MAX_N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    REP(i, N){
        cin >> A[i];
    }
    sort(A, A + N);
    vector<ll> P, P1, P2;
    

    if (N % 2 == 0){
        REP(i, N / 2 -1) P.pb(-2);
        P.pb(-1); P.pb(1);
        REP(i, N / 2 - 1) P.pb(2);
        
        ll ans = 0;
        REP(i, N){
            ans += P[i] * A[i];
        }
        cout << ans << endl;
    }
    else {
        REP(i, (N -1) /2) P1.pb(-2);
        P1.pb(1); P1.pb(1);
        REP(i, (N - 3) / 2) P1.pb(2);

        REP(i, (N - 3) /2) P2.pb(-2);
        P2.pb(-1); P2.pb(-1);
        REP(i, (N - 1) / 2) P2.pb(2);

        ll ans1 = 0, ans2 = 0;
        REP(i, N){
            ans1 += P1[i] * A[i];
            ans2 += P2[i] * A[i];
            
        }
        cout << max(ans1, ans2) << endl;

    }

}