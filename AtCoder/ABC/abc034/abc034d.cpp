#include <bits/stdc++.h>
using namespace std;

   typedef long  ll;

   const double EPS = (1e-10);
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

int n, k;
vector<int> w;
vector<double>p;

bool C(double x){
    // 濃度x以上にできるか
    vector<double> q(n);
    REP(i, n){
        q[i] = w[i] * (p[i] - x);
    }
    sort(q.begin(), q.end(), greater<double>());
    double res = 0;
    REP(i, k){
        // wi * (pi - x) の大きい順にk個の和を取る
        res += q[i];
    }
    if (res >= 0) return true;
    else return false;
}


int main() {
   cin.tie(0);
   ios::sync_with_stdio(false);
   cin >> n >> k;
   w.resize(n);
   p.resize(n);
   REP(i, n){
       cin >> w[i] >> p[i];
   }
   double lb = 0.0;
   double ub = 100.0;
   while (ub - lb > EPS){
       double mid = (lb + ub) / 2;
       C(mid) ? lb = mid : ub = mid;
   }
   cout << ub << endl;
}