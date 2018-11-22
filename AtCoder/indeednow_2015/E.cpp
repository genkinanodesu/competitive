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

const ll MAX_N = 1e5;
ll N;
ll H[MAX_N];
ll I[MAX_N];
set<ll> s;

//BIT
ll bit[MAX_N + 1] = {};
ll sum(ll i){
    // s = A1 + ... + Ai
    ll s = 0;
    while (i > 0){
        s += bit[i];
        i -= i & -i;
    }
    return s;
}
void add(ll i, ll x){
    while (i <= N){
        bit[i] += x;
        i += i & -i;
    }
}


int main(){
    scanf("%lld", &N);
    REP(i, N) {
        scanf("%lld", &H[i]);
        s.insert(H[i]);
    }
    if (s.size() != N) printf("-1\n");
    else{
        pair<ll, ll> X[MAX_N];
        REP(i, N) X[i] = mp(H[i], i);
        sort(X, X + N);
        ll ans = 0;
        REP(i, N){
            ans += (X[i].second - sum(X[i].second + 1)) * X[i].first;
            add(X[i].second + 1, 1);
        }
        printf("%lld\n", ans);

    }
}