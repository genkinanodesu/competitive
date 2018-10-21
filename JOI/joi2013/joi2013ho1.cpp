#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;

   const double EPS = (1e-7);
   const int INF =(1e9);
   const double PI = (acos(-1));
   const int MOD = int(1e9) + 7;

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

bool C(ll k, vector<ll> a){
    REP(i, a.size() - k){
        if (a[i + k] <= a[i] + 2) return true;
    }
    return false;
}


int main() {
   cin.tie(0);
   ios::sync_with_stdio(false);

   ll n; cin >> n;
   vector<ll> lights(n);
   REP(i, n){
       cin >> lights[i];
   }
   vector<ll> diff_accum(n);
   //diff_accum[i] = lights[0] - lights[i]までの範囲で隣同士が同じであるものの個数
   //diff_accum[i + k] <= diff_accum[i] + 2となるiが存在する -> 答えはk + 1以上
   REP(i, n - 1){
       (lights[i] == lights[i + 1]) ? diff_accum[i + 1] = diff_accum[i] + 1 : diff_accum[i + 1] = diff_accum[i];
   }
   ll lb = -1;
   ll ub = n;
   while (ub - lb > 1){
       ll mid = (ub + lb) / 2;
       C(mid, diff_accum) ? lb = mid : ub = mid;
   }
   cout << lb + 1 << endl;
}