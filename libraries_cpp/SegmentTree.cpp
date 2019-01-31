template <class D, class Op> struct SimpleSeg {
    D e;
    Op op;
    long long sz, lg;  //(2^lgに拡張後の)サイズ, lg
    vector<D> d;
 
    SimpleSeg(const vector<D>& v, D _e, Op _op) : e(_e), op(_op) {
        long long n = long long(v.size());
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
SimpleSeg<D, Op> get_simple_seg(V<D> v, D e, Op op) {
    return SimpleSeg<D, Op>(v, e, op);
}


template<typename T> class SegmentTree{
    private:
        long long nodes;
        vector<T> dat;
    public:
        T monoid(T x, T y){
        //monoid演算の内容を記述
            return x * y;
        }
        //宣言と初期化, 要素数を2べきに.
        SegmentTree(long long n){
            nodes = 1;
            while (nodes < n) nodes *= 2;
            dat.resize(2 * nodes - 1, 0);
        }
        SegmentTree(long long n, const& vector<T> v){
            //v.size() = nである必要がある
            nodes = 1;
            while (nodes < n) nodes *= 2;
            dat.resize(2 * nodes - 1, 0);
            copy(v.begin(), v.end(), dat.begin() + nodes - 1);
            for(i = nodes - 2; i >= 0; i--){
                dat[i] = monoid(dat[2 * i + 1], dat[2 * i + 2]);
            }
        }
        void update(long long i, T x){
            //Aiをxに更新する
            i += nodes - 1;
            dat[i] = x;
            while(i > 0){
                i = (i - 1) / 2;
                dat[i] = monoid(dat[2 * i + 1], dat[2 * i + 2]);
            }
        }
        T prod(long long a, long long b, long long k, long long l, long long r){
            //区間[a, b)におけるモノイド積
            if (r <= a || b <= l) return 0;
            if (a <= l && r <= b) return dat[k];
            else{
                T pl = prod(a, b, k * 2 + 1, l, (l + r) / 2);
                T pr = prod(a, b, k * 2 + 2, (l + r) / 2, r);
                return monoid(pl, pr);
            }
        }
        T prod(ll a, ll b) {
            return prod(a, b, 0, 0, nodes);
        }
    };
