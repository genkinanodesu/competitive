#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;
   typedef pair<ll, ll> Pii;
   typedef vector<ll> Vi;
   typedef vector<Vi> VVi;

   const double EPS = (1e-7);
   const ll INF =(1e13);
   const double PI = (acos(-1));
   const ll MOD = ll(1e9) + 7;

   #define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
   #define REPR(i, n) for(ll i = n; i > -1; i--)
   #define FOR(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
   #define ALL(x) (x).begin(),(x).end()
   #define SORT(x) sort((x).begin(), (x).end())
   #define RSORT(x) sort((x).rbegin(), (x).rend())
   #define REVERSE(x) reverse((x).begin(), (x).end())
   #define SZ(x) ((ll)(x).size())
   #define pb push_back
   #define mp make_pair

   //chmax(a, b): a>bならaをbで更新　更新したときにtrueを返す
   //chmin(a, b): a<bならaをbで更新　更新したときにtrueを返す
   template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
   template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

   #define dump(x) cerr<< #x << "= " << (x) << endl;

   ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
   ll pow(ll a, ll b){if (b == 0) return 1; else if (b % 2 == 0) return pow(a * a, b / 2); else return pow(a * a, b / 2) * a;}
   ll pow(ll a, ll b, ll m){if (b == 0) return 1; else if (a == 0) return 0; else if (b % 2 == 0) return (pow((a * a) % m, b / 2, m) % m); else return (pow((a * a) % m, b / 2, m) * a) % m;}
   ll residue(ll a, ll m){return ((a % m) + m) % m;};

   ll dx[4]={1,0,-1,0};
   ll dy[4]={0,1,0,-1};
int main(){
   ll A, B, Q; cin >> A >> B >> Q;
   Vi s(A + 2), t(B + 2), x(Q);
   s[0] = -INF, s[A+1] = INF, t[0] = -INF, t[B+1] = INF;
   REP(i, A) cin >> s[i+1];
   REP(i, B) cin >> t[i+1];
   REP(i, Q) cin >> x[i];

   REP(i, Q){
      ll ans = INF;
      auto lb_s = lower_bound(s.begin(), s.end(), x[i]);
      auto lb_t = lower_bound(t.begin(), t.end(), x[i]);

      ll a[2][2];
      a[0][0] =  *(lb_s - 1);
      a[0][1] = *lb_s;
      a[1][0] = *(lb_t - 1);
      a[1][1] = *lb_t;
      REP(p, 2){
         REP(q, 2){
            REP(r, 2){
               chmin(ans, abs(x[i] - a[p][q]) + abs(a[p][q] - a[1-p][r]));
            }
         }
      }
      cout << ans << endl;
   }

}
