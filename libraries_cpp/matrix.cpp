#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
#define REPR(i, n) for(ll i = n; i > -1; i--)
#define FOR(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)

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

template <class T> class Vec {

  public:
    vector<T> vec;
    long long dim;

    Vec(long long n){
      //n次元ベクトル
      vec = vector<T>(n);
      dim = n;
    }
    Vec zero(long long n){
      //0ベクトル
      Vec B(n);
      for (auto i = 0; i < n; i++) B[i] = 0;
    }
    T &operator[](const long long& i){
      //要素アクセス
      return vec[i];
    }
    Vec operator+(const Vec& A){
      //足し算
      Vec B(dim);
      for (auto i = 0; i < dim; i++){
        B[i] = vec[i] + A[i];
      }
      return B;
    }
    Vec operator-(Vec A){
      //引き算
      Vec B(dim);
      for (auto i = 0; i < dim; i++){
        B[i] = vec[i] - A[i];
      }
      return B;
    }
    Vec sholar_prod(Vec A, T k){
      //スカラー倍
      Vec B(dim);
      for(auto i = 0; i < dim; i++){
        B[i] = vec[i] * k;
      }
      return B;
    }
    T operator*(Vec A){
      //内積
      T ans = 0;
      for(auto i = 0; i < dim; i++){
        ans += A[i] * vec[i];
      }
      return ans;
    }
};

template <class T> class Mat {
  private:
    vector<vector<T>> mat;
    long long row, col;
  public:
    Mat(long long  n, long long m){
      //n行m列の行列
      mat = vector<vector<T>>(n, vector<T>(m));
      row = n, col = m;
    }
    Mat(long long n){
      //n次正方行列
      Mat(n, n);
    }
    vector<T> &operator[](long long i){
      return mat[i];
    }
    Mat identity(long long n){
      //単位行列
      Mat A(n);
      for(auto i = 0; i < n; i++){
        for(auto j = 0; j < n; j++){
          A[i][j] = (i == j);
        }
      }
      return A;
    }
    
    Mat zero(long long n){
      //ゼロ行列
      Mat A(n);
      for(auto i = 0; i < n; i++){
        for(auto j = 0; j < n; j++){
          A[i][j] = 0;
        }
      }
      return A;
    }
    Vec<T> product(Mat A, Vec<T> x){
      //行列A, ベクトルxに対して y = Axを返す
      //A.col = x.dimが必要
      Vec<T> y(A.row);
      for(auto i = 0; i < A.row; i++){
        y[i] = 0;
        for(auto j = 0; j < A.col; j++){
          y[i] += A[i][j] * x[j];
        }
      }
      return y;
    }
    Mat operator*(Mat A){
      //左オペラント.col = A.rowが必要
      Mat B(row, A.col);
      for(auto i = 0; i < row; i++){
        for(auto j = 0; j < A.col; j++){
          B[i][j] = 0;
          for(auto k = 0; k < col; k++){
            B[i][j] += mat[i][k] * A[k][j];
          }
        }
      }
      return B;
    }
    Mat transpose(Mat A){
      //転置
      Mat B(A.col, A.row);
      for(auto i = 0; i < A.col; i++){
        for(auto j = 0; j < A.row; j++){
          B[i][j] = A[j][i];
        }
      }
      return B;
    }
    Mat pow(Mat A, long long e){
      //行列のべき乗
      if(e == 0) return identity(A.row);
      return (e % 2 == 0) ? pow(A * A, e / 2) : A * pow(A * A, e / 2);
    }
};

int main(){
  ll n, m, l; cin >> n >> m >> l;
  Mat<long long> A(n, m), B(m, l);
  REP(i, n) REP(j, m) cin >> A[i][j];
  REP(i, m) REP(j, l) cin >> B[i][j];

  Mat<ll> C(n, l); C = A * B;
  REP(i, n){
    REP(j, l){
      if (j) cout << ' ';
      cout << C[i][j];
    }
    cout << endl;
  }


}