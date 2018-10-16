#include <bits/stdc++.h>
using namespace std;

   typedef long long unsigned int ll;

   const double EPS = (1e-7);
   const int INF =(1e9);
   const double PI = (acos(-1));
   const int MOD = (int(1e9) + 7);

   #define REP(i, n) for(int i = 0; i < (int)(n); i++)
   #define FOR(i, a, b) for (int i = (a); i < (b); i++)
   #define ALL(x) (x).begin(),(x).end()
   #define SORT(x) sort((x).begin(), (x).end())
   #define REVERSE(x) reverse((x).begin(), (x).end())
   #define SZ(x) ((int)(x).size())


   #define dump(x) cerr<< #x << "= " << (x) << endl;

   int gcd(int a,int b){return b?gcd(b,a%b):a;};

   int dx[4]={1,0,-1,0};
   int dy[4]={0,1,0,-1};


ll x_ika(vector<ll> a, vector<ll> b, ll x){
    // a * bにx以下の整数がいくつ存在するか
    // a, bはソート済み
    ll ans = 0;
    REP(i, b.size()){
        ans += upper_bound(ALL(b), x / a[i]) - b.begin();
    }
    return ans;
}
void solve() {
}


int main() {
   cin.tie(0);
   ios::sync_with_stdio(false);
   int n, k;
   cin >> n >> k;
   vector<ll> a(n), b(n);
   REP(i, n){
       cin >> a[i];
   }
   REP(i, n){
       cin >> b[i];
   }
   SORT(a), SORT(b);
   ll lb = a[0] * b[0] - 1;
   ll ub = a[n - 1]  * b[n - 1] + 1;
   // x_ika(a, b, x) >= kとなるxの最小値を二分探索で求める
   // 解の存在範囲は最初(lb, ub]
   // f(x) = x_ika(a, b, x)とする
   // f(mid) >= k なら, 解の存在範囲は(lb, mid]
   // f(mid) < k なら, 解の存在範囲は(mid, ub]
   // 2分探索の終了時点でlb + 1 = ubとなっており, ubが解.
   while (ub - lb > 1){
       ll mid = (lb + ub) / 2;
       if (x_ika(a, b, mid) >= k){
           ub = mid;
       } 
       else{
           lb = mid;
       }
   }
   //解xはつねに lb < x <= ubを満たしている
   cout << ub << endl;
}