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

ll P(vector<ll> a, ll k, ll l){
    //配列aの長さk以上の区間Iのうち, min_K I <= lとなるようなものはいくつあるか
    //b[i + 1] = (a[0] ... a[i]のうちl以下のものの個数)
    //b[j] - b[i] >= K となるような組(j, i)の数え上げに帰着.
    vector<ll> b(a.size() + 1);
    REP(i, a.size()){
        a[i] <= l ? b[i + 1] = b[i] + 1 : b[i + 1] = b[i];
    }
    ll ans = 0;
    ll right = 0;
    REP(i, b.size()){
        if (i > right) right = i;
        while (right < b.size() && b[right] - b[i] < k){
            right++;
        }
        ans += b.size() - right;
    }
    return ans;
}

int main() {
   cin.tie(0);
   ios::sync_with_stdio(false);
   
   //input
   ll n, k, l; cin >> n >> k >> l;
   vector<ll> a(n);
   REP(i, n){
       cin >> a[i];
   }
   ll lb = -1;
   ll ub = n + 1;
   while (ub - lb > 1){
       ll mid = (lb + ub) / 2;
       P(a, k, mid) < l ? lb = mid : ub = mid;
   }
   cout << ub << endl;

}