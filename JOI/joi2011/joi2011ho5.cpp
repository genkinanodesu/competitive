#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;
   typedef pair<ll, ll> Pii;

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

const ll MAX_N = 3e5;
ll N;
Pii bac[MAX_N];

bool f(ll k){
    //部分集合の要素数をk以上にできるか？
    //これでできる. 
    //https://gist.github.com/qnighy/825408より. 天才か.
    priority_queue<ll> ais;
    ll aisum = 0;
    REP(i, N){
        ll ai = bac[i].first;
        ll bi = bac[i].second;
        aisum += ai;
        ais.push(ai);
        while (aisum > k * bi){
            aisum -= ais.top();
            ais.pop();
        }
        if (ais.size() >= k) return true;
    }
    return false;
}

int main(){

    //input
    scanf("%lld", &N);
    REP(i, N){
        ll ai, bi;
        scanf("%lld%lld", &ai, &bi);
        bac[i] = mp(ai, bi);
    }
    sort(bac, bac + N, [](const Pii &x, const Pii &y) {
        return (x.second == y.second) ? (x.first < y.first) : (x.second > y.second);
        });
    ll k_min = 0, k_max = MAX_N + 1;
    while (k_max - k_min > 1){
        ll k_mid = (k_min + k_max) / 2;
        if (f(k_mid)) {k_min = k_mid;}
        else k_max = k_mid;
    }
    printf("%lld\n", k_min);
}