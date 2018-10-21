#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;

   const double EPS = (1e-7);
   const ll INF =(1e9);
   const double PI = (acos(-1));
   const ll MOD = ll(1e9) + 7;

   #define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
   #define REPR(i, n) for(ll i = n; i > -1; i--)
   #define FOR(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
   #define ALL(x) (x).begin(),(x).end()
   #define SORT(x) sort((x).begin(), (x).end())
   #define REVERSE(x) reverse((x).begin(), (x).end())
   #define SZ(x) ((ll)(x).size())
   #define pb push_back
   #define mp make_pair

   //chmax(a, b): a>bならaをbで更新　更新したときにtrueを返す
   //chmin(a, b): a<bならaをbで更新　更新したときにtrueを返す
   template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
   template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

   #define dump(x) cerr<< #x << "= " << (x) << endl;

   int gcd(int a,int b){return b?gcd(b,a%b):a;};

   int dx[4]={1,0,-1,0};
   int dy[4]={0,1,0,-1};


struct bar
{
    // height = 高さ
    // pos = 位置（縦棒pos, pos+1を結ぶ）
    // 縦棒の番号は0-basedとする
    // num.firstとnum.secondを入れ替える
    ll height;
    ll pos;
    ll first;
    ll second;
};

int main() {
   cin.tie(0);
   ios::sync_with_stdio(false);

   //input
   ll n, m, h, k; cin >> n >> m >> h >> k;
   vector<ll> s(n);
   REP(i, n){
       cin >> s[i];
   }
   vector<bar> bars(m);
   REP(i, m){
       ll a, b; cin >> a >> b;
       bars[i].height = b;
       bars[i].pos = a - 1;
   }
   sort(ALL(bars), [](const bar &a, const bar &b) {return a.height < b.height;});

   vector<ll> a(n);
   REP(i, n){a[i] = i;}

   REP(i, m){
       bars[i].first = min(a[bars[i].pos], a[bars[i].pos + 1]);
       bars[i].second = max(a[bars[i].pos], a[bars[i].pos + 1]);
       swap(a[bars[i].pos], a[bars[i].pos + 1]);
       swap(s[bars[i].pos], s[bars[i].pos + 1]);
   }
   ll ans = 0;
   REP(i, k){
       ans += s[i];
   }
   REP(i, m){
       if (a[bars[i].first] < k && a[bars[i].second >= k]){
           chmin(ans, ans - s[a[bars[i].first]] + s[a[bars[i].second]]);
       }
   }
   cout << ans << endl;
}