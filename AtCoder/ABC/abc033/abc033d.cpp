#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;

   const double EPS = (1e-14);
   const int INF =(1e9);
   const double PI = (acos(-1));
   const ll MOD = (ll(1e9) + 7);

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

double arg(ll x, ll y){
    //(x, y)の偏角を計算 0 ～ 2 * PI ラジアン
    if (y >= 0) return atan2(x, y);
    else return atan2(x, y) + 2 * PI;
}

pair<ll, ll> tri_type(vector<double> a){
    //a0, a1, a2, ..., a(n-1) : argments
    //原点から見て直角がいくつ, 鈍角がいくつあるか数える
    //return <right, dull>
    SORT(a);
    ll n = a.size();
    REP(i, n){
        //偏角の列aを2周させておく -> 2分探索の区間を指定しやすい
        a.push_back(a[i] + 2 * PI);
    }
    ll right = 0, dull = 0;
    REP(i, n){
        auto low1 = lower_bound(ALL(a), a[i] + PI / 2 - EPS);
        auto up1 = upper_bound(ALL(a), a[i] + PI / 2 + EPS);
        auto low2 = lower_bound(ALL(a), a[i] + PI * 3 / 2 - EPS);
        auto up2 = upper_bound(ALL(a), a[i] + PI * 3 / 2 + EPS);
        right += (up1 - low1) + (up2 - low2);
        dull += (low2 - up1); 
    }
    right /= 2;
    dull /= 2;
    return make_pair(right, dull);
}

int main() {
   cin.tie(0);
   ios::sync_with_stdio(false);
   ll n; cin >> n;
   vector<vector<ll>> p;
   REP(i, n){
       ll xi, yi;
       cin >> xi >> yi;
       p.push_back({xi, yi});
   }
   ll right = 0, dull = 0, acute = 0; // それぞれ三角形のタイプ別の個数
   REP(i, n){
       vector<double> a;
       REP(j, n){
           if (j != i){
               a.push_back(atan2(p[j][1] - p[i][1], p[j][0] - p[i][0]));
           }
       }
       //これでa = (p[i]を原点として見たときの偏角の列)となった
       right += tri_type(a).first;
       dull += tri_type(a).second;
   }
   acute = n * (n - 1) * (n - 2) / 6 - right - dull;
   cout << acute <<' ' << right << ' ' << dull << endl;
}