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
   ll H, W, K; cin >> H >> W >> K;
   Vi a(H, W), b(W, H);
   REP(i, K){
      ll ri, ci; cin >> ri >> ci; ri--; ci--;
      a[ri]--; b[ci]--;
   }
   //i行目にはa[i]個のコマが, j列目にはb[j]個のコマがある.
   //累積和を取る
   Vi a_sum(H + 1, 0), b_sum(W + 1, 0);
   REP(i, H) a_sum[i+1] = a_sum[i] + a[i];
   REP(j, W) b_sum[j+1] = b_sum[j] + b[j];
   
   ll temp1 = 0, temp2 = 0;
   REP(i, H) temp1 += i * a[i];
   REP(j, W) temp2 += j * b[j];
   ll ans1 = temp1, ans2 = temp2;

   REP(i, H - 1){
      temp1 += 2 * a_sum[i + 1] - a_sum[H];
      chmin(ans1, temp1);
   }
   REP(j, W-1){
      temp2 += 2 * b_sum[j + 1] - b_sum[W];
      chmin(ans2, temp2);
   }
   cout << ans1+ans2 << endl;


}
