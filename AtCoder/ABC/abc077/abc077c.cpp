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

   int gcd(int a,int b){return b?gcd(b,a%b):a;};

   int dx[4]={1,0,-1,0};
   int dy[4]={0,1,0,-1};

void solve() {

}

int main() {
   cin.tie(0);
   ios::sync_with_stdio(false);
   ll N;
   cin >> N;
   vector<ll> A(N), B(N), C(N);
   REP(i, N){
       cin >> A[i];
   }
   REP(i,N){
       cin >> B[i];
   }
   REP(i, N){
       cin >> C[i];
   }
   SORT(A);
   SORT(B);
   SORT(C);
   ll ans = 0;
   REP(i, N){
       ll x = lower_bound(ALL(A), B[i]) - A.begin();
       ll y = C.end() - upper_bound(ALL(C), B[i]);
       ans += x * y;
   }
   cout << ans << endl;
}