#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;
   typedef pair<ll, ll> Pii;
   typedef vector<ll> Vi;
   typedef vector<Vi> VVi;

   const double EPS = (1e-7);
   const ll INF =(1e13);
   const double PI = (acos(-1));
   const ll MOD = ll(1e9) + 7;

   #define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
   #define REPR(i, n) for(ll i = n; i > -1; i--)
   #define FOR(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
   #define ALL(x) (x).begin(),(x).end()
   #define SORT(x) sort((x).begin(), (x).end())
   #define RSORT(x) sort((x).rbegin(), (x).rend()
   #define REVERSE(x) reverse((x).begin(), (x).end())
   #define SZ(x) ((ll)(x).size())
   #define pb push_back
   #define mp make_pair

   //chmax(a, b): a>bならaをbで更新　更新したときにtrueを返す
   //chmin(a, b): a<bならaをbで更新　更新したときにtrueを返す
   template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
   template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

   #define dump(x) cerr<< #x << "= " << (x) << endl;

   ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
   ll pow(ll a, ll b){if (b == 0) return 1; else if (b % 2 == 0) return pow(a * a, b / 2); else return pow(a * a, b / 2) * a;}
   ll pow(ll a, ll b, ll m){if (b == 0) return 1; else if (b % 2 == 0) return (pow(a * a, b / 2, m) % m); else return (pow(a * a, b / 2) * a) % m;}


   ll dx[4]={1,0,-1,0};
   ll dy[4]={0,1,0,-1};
const double r1 = 102.0, r2 = 22.0, h = 44.0;
const double volume = (r1 * r1 + r1 * r2 + r2 * r2) * h * PI / 3.0;
const double time_total = volume / 30.0;
const double time_half = volume / 60.0;
double Xst, Yst, XA, YA, XB, YB, XE, YE;

struct movement{
  double total_time, acc_time, dec_time;
};
movement opt_move(double start, double goal){
  double dist = abs(start - goal);
  movement ans;
  if (abs(goal - start) > 30){
    ans.total_time = (abs(goal - start) - 30) / 0.5 + 120;
    ans.acc_time = 60, ans.dec_time = 60;
  }
  else{
    ans.total_time = 2 * sqrt(dist * 120.0);
    ans.acc_time = ans.total_time / 2;
    ans.dec_time = ans.total_time / 2;
  }
  return ans;
}
int main(){
  cin >> Xst >> Yst >> XA >> YA >> XB >> YB >> XE >> YE;
//  double time = 0;
//  movement X = opt_move(Xst, XA);
//  movement Y = opt_move(Yst, YA);
  printf("%lld,%lld,%lld,%lld,%lld,%lld,%lld,%lld,%lld,%lld,%lld\n", XA, 500, 60, 60, YA, 500, 60, 60, time_half, 0, 0);
  printf("%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n", XB, 500, 60, 60, YB + 2.0, 500, 60, 60, 0, time_half, 0);
  printf("%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n", XE, 500, 60, 60, YE, 500, 60, 60, 0, 0, time_total);
}
