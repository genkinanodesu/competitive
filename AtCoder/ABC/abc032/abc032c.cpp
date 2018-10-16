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


ll n, k;
vector<ll> s;

void solve(){
    if (count(ALL(s), 0) > 0 ) {
        cout << n << endl;
        return;
    }
    else {
        ll right, ans, prod;
        right = ans = 0;
        prod = 1;
        REP(left, n){
            if (right < left) {
                right = left;
                prod = 1;
            }
            while (right < n && prod * s[right] <= k){
                prod *= s[right];
                right++;
            }
            ans = max(ans, right - left);
            prod /= s[left];
        }
        cout << ans << endl;
        return;
    }
}

int main() {
   cin.tie(0);
   ios::sync_with_stdio(false);
   // 入力
   cin >> n >> k;
   REP(i, n){
       ll si;
       cin >> si;
       s.push_back(si);
   }
   solve();
}