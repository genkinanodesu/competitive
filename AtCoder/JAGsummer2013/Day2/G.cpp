#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;
   typedef pair<ll, ll> Pl;

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


   int dx[4]={1,0,-1,0};
   int dy[4]={0,1,0,-1};

const ll MAX_N = 1e5, MAX_Q = 1e4;
ll N, Q, N_;
ll p[MAX_N + 1], x[MAX_N + 1];
ll lt[MAX_Q], rt[MAX_Q];
ll cycle[MAX_N + 1], cycle_sum[MAX_N + 1];


Pl dat[MAX_N * 4];

ll gcd(ll x, ll y){
    if (x < y) return gcd(y, x);
    else if (y != 0){
        return gcd(y, x % y);
    }
    else return x;
}

ll lcm(ll x, ll y){
    return (x / gcd(x, y)) * y;
}
Pl monoid(Pl x, Pl y){
    ll c, s, s1, s2;
    c = lcm(x.first,  y.first);
    s1 = (((c / x.first) % MOD) * x.second) % MOD;
    s2 = (((c / y.first) % MOD) * y.second) % MOD;
    s = (s1 + s2) % MOD;
    return mp(c,s);
}

void init(){
    N_ = 1;
    while (N_ < N) N_ *= 2;

    REP(i, 2 * N_ - 1){
        dat[i] = mp(1, 0);
    }
}
void update(ll i, Pl x){
    //i番目の値をxで更新する
    i += N_ - 1;
    dat[i] = x;

    while (i > 0){
        i = (i - 1) / 2;
        dat[i] = monoid(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
}

Pl query(ll a, ll b, ll k, ll l, ll r){
    if (r <= a || b <= l) return mp(1, 0);
    else if (a <= l && r <= b) return dat[k];
    else{
        Pl vl = query(a, b, k * 2 + 1, l, (l+r)/2);
        Pl vr = query(a, b, k * 2 + 2, (l+r)/2, r);
        return monoid(vl, vr);
    }
}

int main(){
    scanf("%lld%lld", &N, &Q);
//    cin >> N >> Q;
    REP(i, N){
        scanf("%lld", &p[i+1]);
//        cin >> p[i + 1];
    }
    REP(i, Q){
        scanf("%lld%lld", &lt[i], &rt[i]);
//        cin >> lt[i] >> rt[i];
    }

    FOR(i, 1, N + 1){
        x[i] = i; cycle[i] = 1; cycle_sum[i] = i;
        while (p[x[i]] != i){
            x[i] = p[x[i]];
            cycle[i]++;
            cycle_sum[i] = (cycle_sum[i] + x[i]) % MOD;
        }
    }
    init();
    REP(i, N){
        update(i, mp(cycle[i + 1], cycle_sum[i + 1]));
    }
    REP(j, Q){
        printf("%lld\n",  query(lt[j] - 1, rt[j], 0, 0, N_).second);
//        cout << query(lt[j] - 1, rt[j], 0, 0, N_).second << endl;
    }
}
