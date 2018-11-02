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

ll func(ll x, ll y){
    if (x > y) return ((x -1) * x) / 2 + y + 1;
    else if (x == y) return 0;
    else return func(y, x);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //input
    cin >> N;
    bool flag = false;
    REP(k, N + 1){
        if (k * (k  -1) / 2 == N){
            flag = true;
            cout << "Yes" << endl;
            cout << k << endl;
            REP(i, k){
                cout << k -1;
                REP(j, k){
                    if (j != i) cout << ' ' << func(i, j);
                }
                cout << endl;
            }
        }
    }
    if (N == 1){
    cout << "Yes" <<endl;
    cout << 2 << endl;
    cout << "1 1\n" << "1 1\n";
    }
    else if (!flag) cout << "No" << endl;
}