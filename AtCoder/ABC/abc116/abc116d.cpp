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
const ll MAX_N = 1e5;
ll N, K;
Pii sushi[MAX_N];
int main(){
   cin >> N >> K;
   REP(i, N){
      ll type, taste; cin >> type >> taste;
      sushi[i] = mp(taste, type);
   }
   //sushiをtasteの降順にソート
   sort(sushi, sushi + N, greater<Pii>());

   //優先度付きキュー：tasteの降順で並んでいる
   priority_queue<Pii, vector<Pii>, greater<Pii>> q;
   map<ll, ll> cnt;
   ll base = 0, bonus = 0, total;

   REP(i, K){
      q.push(sushi[i]);
      cnt[sushi[i].second]++;
      base += sushi[i].first;
   }
   bonus = cnt.size();
   total = base + bonus * bonus;

   ll i = K;
   while(!q.empty()){
      Pii s = q.top(); q.pop();
      if(cnt[s.second] == 1) continue;
      cnt[s.second]--;
      base -= s.first;
      while(i < N){
         if(cnt[sushi[i].second] == 0){
            cnt[sushi[i].second]++;
            base += sushi[i].first;
            bonus ++;
            chmax(total, base + bonus * bonus);
            break;
         }
         i++;
      }
   }
   cout << total << endl;




}
