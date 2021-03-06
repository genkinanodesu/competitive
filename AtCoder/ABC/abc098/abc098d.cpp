#include <bits/stdc++.h>
using namespace std;

/*
templates for competitive programming
type long long -> type ll 
define constants : EPS, INF, MOD, PI
define macros : REP, FOR, ALL, SORT, REVERSE
define number theory functions: qp(a, b), qp(a, b, mo), gcd(a, b)
define dx, dy
*/
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

int main() {
   cin.tie(0);
   ios::sync_with_stdio(false);
   // input
   ll n; cin >> n;
   vector<int> a(n); 
   REP(i, n) cin >> a[i];

   ll ans = 0;
   ll right = 0;
   ll sum = 0;
   REP(left, n){
       if (left > right){
           left = right;
           sum = 0;
       }
       while ((right < n) && ((sum ^ a[right]) == (sum + a[right]))){
           dump(sum ^ a[right])
           dump(sum + a[right])
           sum += a[right];
           right++;
       }
       dump(left)
       dump(right)
       ans += right - left;
       sum -= a[left];
   }
   cout << ans << endl;
}