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

const ll MAX_N = 2e5;
const ll MAX_digit = 28;
ll N;
ll a[MAX_N];
ll b[MAX_N];

ll xor_digit(ll k){
    //(1 << k)の位に注目したときに, N^2個のXORがいくつになるか
    //O(N log N)で計算できる
    ll ak[MAX_N];
    ll bk[MAX_N];
    ll X = 1 << k;


    REP(i, N){
        ak[i] = (a[i] & (2 * X - 1));
        bk[i] = (b[i] & (2 * X - 1));
    }
    sort(ak, ak + N); sort(bk, bk + N);

    ll ans = 0;
    REP(i, N){
        ans += 
        lower_bound(bk, bk + N, 2 * X - ak[i]) - lower_bound(bk, bk + N, X - ak[i])
        + lower_bound(bk, bk + N, 4 * X - ak[i]) - lower_bound(bk, bk + N, 3 * X - ak[i]);
    }
    ans %= 2;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //input
    cin >> N;
    REP(i, N){
        cin >> a[i];
    }
    REP(i, N){
        cin >> b[i];
    }
    
    ll ans = 0;
    REP(k, MAX_digit + 2){
        ans += (1 << k) * xor_digit(k);
    }
    cout << ans << endl;
    return 0;
}