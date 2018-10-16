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

int a, b, c;

double f(double t){
    return (a * t + b * sin(PI * c * t));
}
int main(){
    cin >> a >> b >> c;
    double lb = 0.0;
    double ub = 101.0;
    double mid = (lb + ub) / 2;
    while (abs(f(mid) - 100) > (1e-7)){
        if (f(mid) > 100){
            ub = mid;
            mid = (lb + ub) / 2;
        }
        else{
            lb = mid;
            mid = (lb + ub) / 2;
        }
    }
    cout << setprecision(12) << mid << endl;
}