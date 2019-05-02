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
   #define RSORT(x) sort((x).rbegin(), (x).rend())
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
   ll pow(ll a, ll b, ll m){if (b == 0) return 1; else if (a == 0) return 0; else if (b % 2 == 0) return (pow((a * a) % m, b / 2, m) % m); else return (pow((a * a) % m, b / 2, m) * a) % m;}
   ll residue(ll a, ll m){return ((a % m) + m) % m;};

   ll dx[4]={1,0,-1,0};
   ll dy[4]={0,1,0,-1};

string counter_to_string(const Vi &v){
  //v.size() = 26
  string ret = "";
  REP(i, 26){
    REP(j, v[i]){
      ret.pb('a' + i);
    }
  }
  return ret;
}

string exp(char c, ll e){
  if(e == 0){
    if(c == 'a') return "a";
    else{ return "aa";}
  }
  vector<string> cand;
  ll n = 0;
  for(ll n = 0; ; n++, e /= 2){
    if(e > 25) {
      if(e % 2 ==1) break;
      continue;
    }
    Vi cnt(26, 0);
    cnt[c - 'a'] = n;
    ll other = e;
    REP(i, 26){
      if(c == 'a' + i) continue;
      if(other <= 0) break;
      cnt[i]++;
      other--;
    }
    string s = counter_to_string(cnt);
    cand.pb(s);
    if(e % 2 == 1) break;
  }
  if(cand.empty()) return "-1";
  SORT(cand); return cand[0];
}
int main(){
  ll q; cin >> q;
  vector<string> ans(q);
  REP(i, q){
    char c; cin >> c;
    ll e; cin >> e;
    ans[i] = exp(c, e);
  }
  REP(i, q) cout << ans[i] << endl;
}
