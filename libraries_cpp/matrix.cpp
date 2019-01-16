#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef ll number;
//const number eps = 1e-8;
typedef vector<number> arr;
typedef vector<arr> mat;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
#define REPR(i, n) for(ll i = n; i > -1; i--)
#define FOR(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)

// O( n )
mat identity(ll n) {
  mat A(n, arr(n));
  REP(i, n){ A[i][i] = 1;}
  return A;
}
// O( n )
number inner_product(const arr &a, const arr &b) {
  number ans = 0;
  REP(i, a.size()){
    ans += a[i] * b[i];
  }
  return ans;
}
// O( n^2 )
arr mul(const mat &A, const arr &x) {
  arr y(A.size());
  REP(i, A.size()){
    REP(j, A[0].size()){
      y[i] = A[i][j] * x[j];
    }
  }
  return y;
}
// O( n^3 )
mat mul(const mat &A, const mat &B) {
  mat C(A.size(), arr(B[0].size()));
  REP(i, C.size()){
    REP(j, C[i].size()){
      REP(k, A[i].size()){
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  return C;
}
// O( n^3 log e )
mat pow(const mat &A, ll e) {
  return e == 0 ? identity(A.size())  :
     e % 2 == 0 ? pow(mul(A, A), e/2) : mul(A, pow(A, e-1));
}
