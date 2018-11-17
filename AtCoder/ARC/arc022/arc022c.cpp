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

   //input
   ll n; cin >> n;
   vector<ll> a(n);
   REP(i, n) cin >> a[i];

   ll right = 0, ans = 0;
   set<ll> s; //key = 味Ai, value = Aiの出現回数
   REP(left, n){
       if (left > right){
           right = left;
       }
       while (right < n && s.count(a[right]) == 0){
           s.insert(a[right]);
           right++;
       }
       dump(left)
       dump(right)
       ans = max(ans, right- left);
       s.erase(a[left]);
   }
   cout << ans << endl;
}