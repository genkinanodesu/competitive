#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;
   typedef pair<ll, ll> Pii;
   typedef vector<ll> Vi;
   typedef vector<Vi> VVi;

   const double EPS = (1e-7);
   const ll INF =(1e13);
   const double PI = (acos(-1));
   const ll MOD = (1ll << 32);

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

ll residue(ll a, ll m){return ((a % m) + m) % m;};

   ll dx[4]={1,0,-1,0};
   ll dy[4]={0,1,0,-1};


template <class T, long long n, long long m> struct Mat : array<array<T, m>, n>{
  //型Tを要素に持つn行m列の行列
  using array<array<T, m>, n> :: array;
  using array<array<T, m>, n> :: size;
  long long row() const{return (long long)(size());}
  long long col() const{return (long long)((*this)[0].size());}
  Mat operator* (const Mat &r) const{
    assert(col() == r.row());
    Mat res = Mat();
    for (long long i = 0; i < row(); i++){
      for (long long j = 0; j < r.col(); j++){
        res[i][j] = 0;
        for (long long k = 0; k < col(); k++){
          res[i][j] += (*this) [i][k] * r[k][j];
        }
      }
    }
    return res;
  }

  Mat& operator*=(const Mat& r){return *this = *this * r;}
};

template <class D, class Op> struct SimpleSeg {
    D e;
    Op op;
    long long sz, lg;  //(2^lgに拡張後の)サイズ, lg
    vector<D> d;
 
    SimpleSeg(const vector<D>& v, D _e, Op _op) : e(_e), op(_op) {
        long long n = (long long)(v.size());
        lg = 1;
        while ((1ll << lg) < n) lg++;
        sz = 1ll << lg;
        d = vector<D>(2 * sz, e);
        for (long long i = 0; i < n; i++) d[sz + i] = v[i];
        for (long long i = sz - 1; i >= 0; i--) {
            update(i);
        }
    }
 
    void update(long long k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
 
    void set(long long p, D x) {
        p += sz;
        d[p] = x;
        for (long long i = 1; i <= lg; i++) update(p >> i);
    }
 
    D single(long long p) { return d[p + sz]; }
 
    D prod(long long a, long long b, long long l, long long r, long long k) {
        if (b <= l || r <= a) return e;
        if (a <= l && r <= b) return d[k];
        long long mid = (l + r) / 2;
        return op(prod(a, b, l, mid, 2 * k), prod(a, b, mid, r, 2 * k + 1));
    }
    D prod(long long a, long long b) { return prod(a, b, 0, sz, 1); }
};
 
template <class D, class Op>
SimpleSeg<D, Op> get_simple_seg(vector<D> v, D e, Op op) {
    return SimpleSeg<D, Op>(v, e, op);
}

const ll MAX_Q = 1e5;
const string D = "DISCO";
string S;
ll Q;
ll L[MAX_Q], R[MAX_Q];

int main(){
  cin >> S >> Q;
  REP(i, Q) cin >> L[i] >> R[i];

  using M = Mat<unsigned int, 6, 6>;
  M e = M();
  REP(i, 6) e[i][i] = 1;

  M X[6];
  REP(i, 5){
    X[i] = e;
    X[i][i + 1][i] = 1;
  }
  vector<M> V(S.size());
  REP(i, S.size()){
    REP(j, 5){
      if(S[i] == D[j]) V[i] = X[j];
    }
  }
  auto seg = get_simple_seg(V, e, [&](const M &l, const M &r){return r * l;});
  REP(i, Q){
    M p = seg.prod(L[i] - 1, R[i]);
    cout << (p[5][0]) << endl;
    /*
    printf("p = prod(%lld, %lld):\n", L[i] - 1, R[i]);
    REP(x, 6){
      REP(y, 6){
        printf("%lld ", p[x][y]);
      }
      printf("\n");
    }

    */
  }
}
