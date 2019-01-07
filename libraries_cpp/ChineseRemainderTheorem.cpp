//負の数の剰余でもバグが出ないように
inline ll mod(ll a, ll m){
    return (a % m + m) % m;
}

//拡張Euclidの互除法
//ap + bq = gcd(a, b) なる(p, q)を求め, d = gcd(a, b)をリターン
ll extGcd(ll a, ll b, ll &p, ll &q){
    if (b == 0) {
        p = 1; q = 0; return a;
    }
    ll d = extGcd(b, a % b, q, p);
    q -= a / b * p;
    return d;
}

//中国剰余定理
//x \equiv b_i (mod m_i)をみたすx \equiv r (mod LCM(mi))を求める
//return値を(r, m)とすると解はx \equiv r (mod m)
//解なしの場合は(0, 1)をreturn
pair<ll, ll> CRT(const vector<ll> &b, const vector<ll> &m){
    ll r = 0, M = 1; // 初期解
    REP(i, (ll)b.size()){
        ll p, q;
        ll d = extGcd(M, m[i], p, q); //p * (M /d) \equiv 1 (mod mi / d)
        if ((b[i] - r) % d != 0) return mp(0, -1);
        ll tmp = ((b[i] - r) / d * p ) % (m[i] / d);
        r += M * tmp;
        M *= m[i] / d;
    }
    return mp(mod(r, M), M);
}



// 逆元計算 (ここでは a と m が互いに素であることが必要)
long long modinv(long long a, long long m) {
    long long x, y;
    extGCD(a, m, x, y);
    return mod(x, m); // 気持ち的には x % m だが、x が負かもしれないので
}

// Garner のアルゴリズム, x%MOD, LCM%MOD を求める (m は互いに素でなければならない)
// for each step, we solve "coeffs[k] * t[k] + constants[k] = b[k] (mod. m[k])"
//      coeffs[k] = m[0]m[1]...m[k-1]
//      constants[k] = t[0] + t[1]m[0] + ... + t[k-1]m[0]m[1]...m[k-2]
long long Garner(vector<long long> b, vector<long long> m, long long MOD) {
    m.push_back(MOD); // banpei
    vector<long long> coeffs((int)m.size(), 1);
    vector<long long> constants((int)m.size(), 0);
    for (int k = 0; k < (int)b.size(); ++k) {
        long long t = mod((b[k] - constants[k]) * modinv(coeffs[k], m[k]), m[k]);
        for (int i = k+1; i < (int)m.size(); ++i) {
            (constants[i] += t * coeffs[i]) %= m[i];
            (coeffs[i] *= m[k]) %= m[i];
        }
    }
    return constants.back();
}