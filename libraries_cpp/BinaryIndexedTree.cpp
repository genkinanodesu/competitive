//一般的にアーベル群上の演算なら扱えるが, ここでは一番よく使うBITのみ.

class BIT{
    //1-index, A1, A2, ..., A_Mの更新および累積和をO(logM)で求める.
    public:
        vector<ll> bit;
        ll M;

    BIT(ll M):
        //宣言と初期化
        bit(vector<ll>(M+1, 0)), M(M) {}

    ll sum(ll i) {
        if (!i) return 0;
        return bit[i] + sum(i-(i&-i));
    }

    void add(ll i, ll x) {
        if (i > M) return;
        bit[i] += x;
        add(i+(i&-i), x);
    }
};
