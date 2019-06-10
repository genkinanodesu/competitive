#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;

class Order {      /** オーダ **/
public:
    int r;	/** オーダ番号    : Order number */
    int i;  /** 品目番号      : Item number */
    int e;  /** 最早開始時刻  : Earliest start time */
    int d;  /** 納期          : Deadline */
    int q;  /** 製造数量      : Manufacturing quanity */
    int pr; /** 粗利金額      : Gross profit */
    Order(int _r, int _i, int _e, int _d, int _q, int _pr) {
        r = _r;
        i = _i;
        e = _e;
        d = _d;
        q = _q;
        pr = _pr;
    }
};
class Bom {        /** BOM **/
public:
    int p = 0;         /** 工程数       : Process number */
    vector<int> times; /** 製造スピード : Manufacturing spead */
    vector<int> pTom;  /** 割り当て設備 : Process to Machine */
    Bom(int _P) {
        times.resize(_P);
        pTom.resize(_P);
    }
};
class Capacity {   /** 能力増加 **/
public:
    int m;  /** 設備番号             : Machine number */
    int d;  /** 日                   : day */   
    int ac; /** 能力増加数           : Additional capacity */
    Capacity (int _m, int _d, int _ac) {
        m = _m;
        d = _d;
        ac = _ac;
    }
};
class Operation {  /** 作業 **/
public:
    int r;  /** オーダ番号         : Order number */
    int p;  /** 工程番号           : Process number */
    int m;  /** 設備番号           : Machine number */
    int t1; /** 製造開始時刻       : Manufacturing start time */
    int t2; /** 製造終了時刻       : Manufacturing end time */
    Operation(int _r, int _p, int _m, int _t1, int _t2) {
        r = _r;
        p = _p;
        m = _m;
        t1 = _t1;
        t2 = _t2;
    }
};
int M;     /** 設備数                   : Number of machines */
int I;     /** 品目数                   : Number of items */
int P;     /** 最大工程数               : Max number of processes*/
int R;     /** 注文数                   : Number of orders */
int BL;    /** BOM行数                  : Number of BOM lines */
const int DEFAULT_CAPACITY = 8;
const int MAX_CAPACITY = 1000000;
const int SECONDS_A_DAY = 86400;
const int MAX_DAY = 1000;
vector<int> C;    /** Cm 設備mの能力増加コスト : Machine cost multiplier */
vector<int> D;    /** Dm 設備mの製造時間係数   : Machine manufacturing time multiplier */

vector<Order> orders;
vector<Operation> operations;
vector<Capacity> capacities;
vector<Bom> boms;
vector<vector<int> > mdToAc;
vector<vector<Pii> > rpToTime;

void readProblem() {
    /* 問題を読み込み。 : Load the problem. */
    string _s;
    cin >> _s >> M >> I >> P >> R >> BL;
    cin >> _s;
    C.resize(M);
    for (int m = 0; m < M; ++m) {
        cin >> C[m];
    }
    cin >> _s;
    D.resize(M);
    for (int m = 0; m < M; ++m) {
        cin >> D[m];
    }
    boms.assign(I, Bom(P));
    for (int n = 0; n < BL; ++n) {
        int i, p, m, s;
        cin >> _s >> i >> p >> m >> s;
        Bom& bom = boms[i-1];
        bom.p = max(bom.p, p);
        bom.times[p-1] = s;
        bom.pTom[p-1] = m-1;
    }
    for (int n = 0; n < R; ++n) {
        int r, i, e, d, q, pr;
        cin >> _s >> r >> i >> e >> d >> q >> pr;
        orders.push_back(Order(r-1, i-1, (e-1)*SECONDS_A_DAY, (d-1)*SECONDS_A_DAY, q, pr));
    }
    mdToAc.assign(M, vector<int>(MAX_DAY+1, 0));
    rpToTime.assign(R, vector<Pii>(P, Pii(0, 0)));
    return;
}
void writeSolution() {
    /* 結果を出力。: Output the results. */
    cout << capacities.size() << endl;
    for (Capacity capa : capacities) {
        cout << capa.m+1 << '\t' << capa.d << '\t' << capa.ac << endl;
    }
    cout << operations.size() << endl;
    for (Operation ope : operations) {
        cout << ope.r+1 << '\t' << ope.p+1 << '\t' << ope.m+1 << '\t' << ope.t1 << '\t' << ope.t2 << endl;
    }
    return;
}
void forwardAssign() {
    /* 各設備の前回の製造終了時刻 : Previous manufacturing end time of each machine */
    vector<int> mToPreviousT2(M, 0);

    /* オーダ順に作業をフォワードで割り付ける。: Assign operations forward according to order code. */
    for (int r = 0; r < R; ++r) {
        int q = orders[r].q;
        int i = orders[r].i;
        Bom& bom = boms[i];
        int prevT2 = 0;   /* 前工程の終了時間。: Ending time of the previous process. */
        for (int p = 0; p < bom.p; ++p) {
            int m = bom.pTom[p];
            int t1 = 0;
            if (p == 0) {
                t1 = max(mToPreviousT2[m], orders[r].e);
            } else {
                t1 = max(mToPreviousT2[m], prevT2);
            }
            /* 工程終了時間を計算。(小数第一位以下は切り上げ)。: Acquire the process ending time (round up to the nearest integer). */
            ll _t1 = t1;
            ll needResourceAmount = q*bom.times[p]*D[m];
            ll nDay = (_t1 + SECONDS_A_DAY)/SECONDS_A_DAY;
            ll ac = mdToAc[m][nDay];
            ll resourceAmountADay = (nDay*SECONDS_A_DAY - _t1) * (DEFAULT_CAPACITY + ac); 
            while (needResourceAmount > resourceAmountADay) {
                needResourceAmount -= resourceAmountADay;
                ++nDay;
                _t1 = (nDay-1)*SECONDS_A_DAY;
                ac = mdToAc[m][nDay];
                resourceAmountADay = SECONDS_A_DAY * (DEFAULT_CAPACITY + ac);   
            }
            ll capa = DEFAULT_CAPACITY + ac;
            /* 下行では int t2 = _t1 + ceil((double)needResourceAmount / capa); を丸め誤差が生じないように計算している。*/
            /* In the next line, using "int t2 = _t1 + ceil((double)needResourceAmount / capa);" would cause small rounding error. */
            int t2 = _t1 + ((needResourceAmount+capa-1)/capa);

            rpToTime[r][p] = Pii(t1, t2);

            /* 現在の設備状況の更新。: Update machine status. */
            mToPreviousT2[m] = t2;
            prevT2 = t2;
        }
    }
    return;
}
ll evaluation() {
    ll grossP = 0;
    for (int r = 0; r < R; ++r) {
        int p = boms[orders[r].i].p -1 ;
        if (rpToTime[r][p].second <= orders[r].d) grossP += orders[r].pr;
    }
    double cost = 0;
    for (int m = 0; m < M; ++m) {
        for (int d = 1; d <= MAX_DAY; ++d) {
            if (mdToAc[m][d] != 0) cost += C[m] * pow(mdToAc[m][d], 1.1);
        }
    }
    ll v = ll(grossP-ceil(cost));
    return v;
}

void save() {
    capacities.clear(); operations.clear();
    for (int m = 0; m < M; ++m) {
        for (int d = 1; d <= MAX_DAY; ++d) {
            if (mdToAc[m][d] != 0) capacities.push_back(Capacity(m, d, mdToAc[m][d]));
        }
    }
    for (int r = 0; r < R; ++r) {
        for (int p = 0; p < boms[orders[r].i].p; ++p) {
            operations.push_back(Operation(r, p, boms[orders[r].i].pTom[p], rpToTime[r][p].first, rpToTime[r][p].second));
        }
    }
}
void solve() {
    /* ordersをオーダ番号でソートする。: Sort orders by order code. */
    sort(orders.begin(), orders.end(), [](const Order& o1, const Order& o2){ return o1.r < o2.r; }); 

    /* 各設備の1日目~10日目に能力を追加。: Adding capacities of each machine from day 1 to 10. */
    for (int m = 0; m < M; ++m) {
        for (int d = 1; d <= 10; ++d) {
            mdToAc[m][d] = 15;
        }
    }
    forwardAssign();
    save();

    return;
}
void run() {
    readProblem();
    solve();
    writeSolution();
}
int main() {
    run();
    return 0;
}
