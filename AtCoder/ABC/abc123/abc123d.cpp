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

map<ll, ll> dp;
ll bs(ll n, const Vi &P, const Vi &Q){
   //p, q: sorted. return #(p, q) : P[p] + Q[q] >= n
   if(dp.find(n) != dp.end()) return dp[n];
   ll ans = 0;
   for(auto &p : P){
      ans += Q.end() - lower_bound(Q.begin(), Q.end(), n - p);
   }
   dp[n] = ans;
   return ans;
}

ll x, y, z, K;
Vi a, b, c, ab;
int main(){
   cin >> x >> y >> z >> K;
   a.resize(x); b.resize(y); c.resize(z);
   REP(i, x) cin >> a[i];
   REP(i, y) cin >> b[i];
   REP(i, z) cin >> c[i];
   REP(i, x){
      REP(j, y){
         ab.pb(a[i] + b[j]);
      }
   }
   SORT(a); SORT(b), SORT(c); SORT(ab);
   if(ab.size() >= K + 2){
      ab.erase(ab.begin(), ab.end() - K - 1);
   }
   ll max_sum = a[x-1] + b[y-1] + c[z-1] + 1;
   ll temp = 0;
   Vi ans(K);
   for(ll k = K - 1 ; k >= 0 ; k--){
      //a + b + c >= n となる(a, b, c)がk個以上ある最大のnを2分探索.
      ll lb = temp, ub = max_sum;
      while(ub - lb > 1){
         ll mid = (lb + ub) / 2;
         (bs(mid, c, ab) <= k) ? ub = mid : lb = mid;
      }
      ans[k] = lb; 
      temp = lb;
   }
   REP(k, K) cout << ans[k] << endl;
}
