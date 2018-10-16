#define NOMINMAX
#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;

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

ll r, b;
ll x, y;


bool C(ll k){
    // 花束の個数をk個にできるか
    // px + q <= r, p + qy <= b, p + q = kとおいてpについて解くと,
    // (ky - b) / (y - 1) <= p <= (r - k)/(x - 1)
    // 数学的にきれいに変形すると, floor(r-k/x-1) + floor(b-k / y-1) <= k

   if (k > r || k > b) return false;
   else {
       ll ub = (r - k) / (x - 1);
       ll t = max(ll (0), (k * y - b));
       ll lb = (t + y - 2) / (y - 1); 
       // 整数の除算は0周りでいやな挙動をする. k >= 0は確定なので, lb < 0のときは考えずに済むようにしておく.
       if (lb <= ub)  return true;
       else return false;
       }
   
   /* 想定解はこれ. きれい.
   if (k <= r && k <= b && ((r - k) / (x - 1) + (b - k) / (y - 1)) >= k){
       return true;
   }
   else return false;
   */
}
int main(){
    cin >> r >> b >> x >> y;
    ll lb = -1;
    ll ub = min(r, b) + 1;
    while (ub - lb > 1){
        ll mid = (lb + ub) / 2;
        C(mid) ? lb = mid: ub = mid;
    }
    cout << lb << endl;
}
