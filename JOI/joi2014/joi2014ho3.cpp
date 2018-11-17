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

   int gcd(int a,int b){return b?gcd(b,a%b):a;};

   int dx[4]={1,0,-1,0};
   int dy[4]={0,1,0,-1};

int n;
vector<ll> a;
ll s;

vector<pair<int, ll>> shakutori(ll k){
    /* 
    a[i] + a[i + 1] + ... + a[j] >= k となる最初のjをとって,
    b[i] = <j, a[i] + ... + a[j]>
    を返す
    */
    vector<pair<int, ll>> b(n);
    int temp_index = -1;
    ll temp_sum = 0;
    REP(i, n){
        if (temp_index < i){
            temp_index = i;
            temp_sum = a[i];
        }
        while (temp_sum < k){
            temp_index =temp_index + 1;
            temp_sum += a[temp_index];
        }
        b[i].first = temp_index;
        b[i].second = temp_sum;
        //次のステップへ向けて値を更新
        temp_sum -= a[i];
    }
    return b;
}

bool C(ll k){
    //すべてのバームクーヘンをk以上にできるか
    vector<pair<int, ll>> b = shakutori(k);
    REP(i, n){
        int j = b[i].first + 1;
        if (j < n){
            int k = b[j].first + 1;
            if (k < n){
                if (s - b[i].second - b[j].second >= k) return true;
            }
        }
    }
    return false;
}
int main() {
   cin.tie(0);
   ios::sync_with_stdio(false);
   cin >> n;
   a.resize(2 * n);
   REP(i, n){
       cin >> a[i];
       a[i + n] = a[i];
   }
   //aをサイズ2 * nでとっておく. 一周しても大丈夫
   s = accumulate(a.begin(), a.begin() + n, 0);

   ll lb = 0;
   ll ub = s / 3 + 1;
   while (ub -lb > 1){
       ll mid = (lb + ub) / 2;
       C(mid)? lb = mid : ub = mid;
   }
   cout << lb << endl;
}