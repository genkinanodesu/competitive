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
ll N;
ll A[MAX_N + 1];
ll B[MAX_N + 1];
ll C[MAX_N + 1];

ll BIT[MAX_N + 1];

void init(ll n){
    REP(i, n + 1) BIT[i] = 0;
}
ll make_max(ll i){
    //1～iの最大値を求める
    ll M = 0;
    while (i > 0){
        chmax(M, BIT[i]);
        i -= i & -i;
    }
    return M;
}
void update(ll i, ll x){
    //i番目にxを代入し、各区間の最大値を更新する
    while (i <= N){
        chmax(BIT[i], x);
        i += i & -i;
    }
}

int main(){
    //input
    //A[i] = 本iの重さ (1-indexed)
    //B[j] = j番目にある本の番号 (1-indexed)
    //C[i] = 本iの場所
    //つまりC[B[j]] = j

    cin >> N;
    ll sum = 0;
    FOR(i, 1, N + 1){
        cin >> A[i];
        sum += A[i];
    }
    FOR(j, 1, N + 1){
        cin >> B[j];
        C[B[j]] = j;
    }
    init(N);
    FOR(j, 1, N + 1){
        update(C[j], make_max(C[j] - 1) + A[j]);
        //REP(i, N + 1) cout << BIT[i] << ' ';
        //cout << endl;
    }
    cout << 2 * (sum - make_max(N)) << endl;
}