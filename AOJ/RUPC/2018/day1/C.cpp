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

int main(){
    //input
    ll n; cin >> n;
    vector<ll> a(n); 
    REP(i, n){
        cin >> a[i];
    }
    
    map<ll, ll> p;
    map<ll, ll> q;
    ll diff = 0;
    REP(i, n){
        if (a[i] != a[n - 1 - i]){
            diff += 2 * (p[a[i]] - q[a[i]]) - 2 * (p[a[n - 1 - i]] - q[a[n - 1 - i]]) + 2;
        }
        if (diff == 0){
            cout << i + 1;
            if (i != n - 1){
                cout << ' ';
            }
        }
        p[a[i]] += 1;
        q[a[n - 1 - i]] += 1;
    }
    cout << endl;
    return 0;
}