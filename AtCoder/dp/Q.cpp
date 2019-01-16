#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;
   typedef pair<ll, ll> Pii;

   const double EPS = (1e-7);
   const ll INF =(1e13);
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

   ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
   ll pow(ll a, ll b){if (b == 0) return 1; else if (b % 2 == 0) return pow(a * a, b / 2); else return pow(a * a, b / 2) * a;}


   ll dx[4]={1,0,-1,0};
   ll dy[4]={0,1,0,-1};

const ll MAX_N = 2e5;
ll N;
ll a[MAX_N], b[MAX_N + 1], h[MAX_N];

ll monoid(ll x, ll y) {
  return max(x, y);
}

class SegmentTree{
    private:
        ll n;
        vector<ll> dat;
    public:
        //宣言と初期化, 要素数を2べきに.
        SegmentTree(ll N){
            n = 1;
            while (n < N) n *= 2;
            dat.resize(2 * n - 1, 0);
        }
        void update(ll i, ll x){
            //Aiをxに更新する
            i += n - 1;
            dat[i] = x;
            while(i > 0){
                i = (i - 1) / 2;
                dat[i] = monoid(dat[i * 2 + 1], dat[2 * i + 2]);
            }
        }
        ll prod(ll a, ll b, ll k, ll l, ll r){
            //区間[a, b)におけるモノイド積
            if (r <= a || b <= l) return 0;
            if (a <= l && r <= b) return dat[k];
            else{
                ll pl = prod(a, b, k * 2 + 1, l, (l + r) / 2);
                ll pr = prod(a, b, k * 2 + 2, (l + r) / 2, r);
                return monoid(pl, pr);
            }
        }
        ll prod(ll a, ll b) {
            return prod(a, b, 0, 0, n);
        }
};

int main(){
  cin >> N;
  REP(i, N){
    cin >> h[i];
    b[h[i]] = i + 1;
    //ex)h[i] = 3, 1, 4, 2 -> b[i] = 0, 2, 4, 1, 3
  }
  REP(i, N){
    cin >> a[i];
    //ex)a[i] = 10, 20, 30, 40
  }
  SegmentTree t(N);
  REP(i, N){
    t.update(b[i + 1] - 1, t.prod(0, b[i + 1]) + a[b[i + 1] - 1]);
    /*
    REP(j, N){
      printf("t.prod(0, %lld) = %lld\n", j + 1, t.prod(0, j + 1));
    }
    */
  }
  cout << t.prod(0, N) << endl;
}
