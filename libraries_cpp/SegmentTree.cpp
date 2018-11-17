//monoid演算は整数上の単位元が0の演算として定義済みとしている. そうでない場合は適宜書き換える.
//テンプレート機能を使えばもっと一般的な書き方ができるが, ひとまず実用を重視.

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
