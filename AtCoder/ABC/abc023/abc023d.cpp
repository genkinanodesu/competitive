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

bool C(ll k, vector<ll> h, vector<ll> s){
    //得点 <= kとできるか
    //すなわち、すべてのiに対しHi + Si * ai <= kが成り立つようなaiがうまくとれるか
    int n = h.size();
    vector<ll> a(n);
    REP(i, n){
        if (k < h[i] ){
            return false;
        }
        else {
            a[i] = (k - h[i]) / s[i];
        }
    }
    SORT(a);
    REP(i, n){
        if (a[i] < i){
            return false;
        }
    }
    return true;
}


int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    vector<ll> s(n);
    REP(i, n){
        cin >> h[i] >> s[i];
    }
    ll max_h = *max_element(ALL(h));
    ll max_s = *max_element(ALL(s));
    ll ub = max_h + max_s * n;
    ll lb = -1;
    while (ub - lb > 1){
        ll mid = (ub + lb) / 2;
        C(mid, h, s) ? ub = mid : lb = mid;
    }
    cout << ub << endl;
}
