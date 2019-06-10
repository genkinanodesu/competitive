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
class Order {      /** オーダ **/
public:
    int r;	/** オーダ番号    : Order number */
    int i;  /** 品目番号      : Item number */
    int e;  /** 最早開始日    : Earliest start day */
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
    int p = 0;              /** 工程番号     : Process number */
    std::vector<int> times; /** 製造スピード : Manufacturing spead */
    std::vector<int> pTom;  /** 割り当て設備 : Process to Machine */
    Bom(int _P) {
        times.resize(_P);
        pTom.resize(_P);
    }
};
class Capacity {   /** 能力増加 **/
public:
    int m;  /** 設備番号             : Machine number */
    int d;  /** 日                   : Day */   
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
int AL;    /** 能力追加データ数         : Number of additional capacity data */
int OL;    /** 作業数                   : Number of operations */
const int DEFAULT_CAPACITY = 8;
const int SECONDS_A_DAY = 86400;
const int MAX_DAY = 1000;
const int MAX_ADDITIONAL_CAPA = 1000000;
std::vector<int> C;    /** Cm 設備mの能力増加コスト : Machine additional capacity cost multiplier */
std::vector<int> D;    /** Dm 設備mの製造時間係数   : Machine manufacturing time multiplier */

std::vector<Order> orders;
std::vector<Operation> operations;
std::vector<Capacity> capacities;
std::vector<Bom> boms;
std::vector<std::vector<int> > mdToAc;
inline int _t2(int i, int p, int q, int t1) {
    /* 工程終了時間を計算。(小数第一位以下は切り上げ)。*/
    int m = boms[i].pTom[p];
    long long needResourceAmount = q*boms[i].times[p]*D[m];
    long long nDay = (t1 + SECONDS_A_DAY)/SECONDS_A_DAY;
    long long ac = mdToAc[m][nDay];
    long long resourceAmountADay = (nDay*SECONDS_A_DAY - t1) * (DEFAULT_CAPACITY + ac); 
    while (needResourceAmount > resourceAmountADay) {
        needResourceAmount -= resourceAmountADay;
        ++nDay;
        t1 = (nDay-1)*SECONDS_A_DAY;
        ac = mdToAc[m][nDay];
        resourceAmountADay = SECONDS_A_DAY * (DEFAULT_CAPACITY + ac);   
    }
    long long capa = DEFAULT_CAPACITY + ac;
    int t2 = t1 + ((needResourceAmount+capa-1)/capa);
    return t2;
}
int main(int argc, char const* argv[]) {
    try {
        std::ifstream in(argv[1]);
        std::ifstream out(argv[2]);

        std::string str;
        in >> str >> M >> I >> P >> R >> BL;
        in >> str;
        C.resize(M);
        for (int m = 0; m < M; ++m) {
            in >> C[m];
        }
        in >> str;
        D.resize(M);
        for (int m = 0; m < M; ++m) {
            in >> D[m];
        }
        boms.assign(I, Bom(P));
        for (int n = 0; n < BL; ++n) {
            int i, p, m, s;
            in >> str >> i >> p >> m >> s;
            boms[i-1].p = std::max(boms[i-1].p, p);
            boms[i-1].times[p-1] = s;
            boms[i-1].pTom[p-1] = m-1;
        }
        int totalOperations = 0;
        for (int n = 0; n < R; ++n) {
            int r, i, e, d, q, pr;
            in >> str >> r >> i >> e >> d >> q >> pr;
            orders.push_back(Order(r-1, i-1, (e-1)*SECONDS_A_DAY, (d-1)*SECONDS_A_DAY, q, pr));
            totalOperations += boms[i-1].p;
        }

        out >> AL;
        if (AL > MAX_DAY*M) {
            std::cerr << "number of additional capacities is too large." << std::endl;
            return 1;
        }
        for (int n = 0; n < AL; ++n) {
            int m, d, ac;
            out >> m >> d >> ac;
            if (out.eof()) {
                std::cerr << "output is too small" << std::endl;
                return 1;
            }
            if (m <= 0 || m > M) {
                std::cerr << "m is out of range." << std::endl;
                return 1;
            }
            if (d <= 0 || d > MAX_DAY) {
                std::cerr << "d is out of range." << std::endl;
                return 1;
            }
            if (ac <= 0 || ac > MAX_ADDITIONAL_CAPA) {
                std::cerr << "ac is out of range." << std::endl;
                return 1;
            }
            capacities.push_back(Capacity(m-1, d, ac));
        }
        out >> OL;
        if (OL != totalOperations) {
            std::cerr << "invalid number of operations." << std::endl;
            return 1;
        }
        for (int n = 0; n < OL; ++n) {
            int r, p, m, t1, t2;
            out >> r >> p >> m >> t1 >> t2;
            if (out.eof()) {
                std::cerr << "output is too small" << std::endl;
                return 1;
            }
            if (m <= 0 || m > M) {
                std::cerr << "m is out of range." << std::endl;
                return 1;
            }
            if (r <= 0 || r > R) {
                std::cerr << "r is out of range." << std::endl;
                return 1;
            }
            if (p <= 0 || p > P) {
                std::cerr << "p is out of range." << std::endl;
                return 1;
            }
            if (t1 < 0) {
                std::cerr << "t1 must be nonnegative." << std::endl;
                return 1;
            }
            if (t2 < 0 || t2 > SECONDS_A_DAY*MAX_DAY) {
                std::cerr << "t2 is out of range." << std::endl;
                return 1;
            }
            operations.push_back(Operation(r-1, p-1, m-1, t1, t2));
        }




        /* 能力追加データ制約チェック */
        std::sort(capacities.begin(), capacities.end(), [](const Capacity& c1, const Capacity& c2){
                if (c1.m != c2.m) {
                    return c1.m < c2.m;
                } else {
                    return c1.d < c2.d;
                }
                });

        for (int i = 0; i+1 < capacities.size(); ++i) {
            if (capacities[i].m == capacities[i+1].m && capacities[i].d == capacities[i+1].d) {
                std::cerr << "能力追加データは、同一設備、同一日は複数行に分けず、1行にまとめてください。" << std::endl;
                return 1;
            }
        }

        mdToAc.assign(M, std::vector<int>(MAX_DAY+1, 0));
        for (Capacity capa : capacities) {
            mdToAc[capa.m][capa.d] = capa.ac;
        }


        /* 作業データ制約チェック */
        std::sort(orders.begin(), orders.end(), [](const Order& o1, const Order& o2){ return o1.r < o2.r; }); 
        std::sort(operations.begin(), operations.end(), [](const Operation& o1, const Operation& o2){
                if (o1.r != o2.r) {
                    return o1.r < o2.r;
                } else {
                    return o1.p < o2.p;
                }
                });


        std::vector<int> mToPreviousT1(M, 0);
        std::vector<int> mToPreviousT2(M, 0);
        int idx = 0;
        for (int r = 0; r < R; ++r) {
            int prevT2 = 0;
            for (int p = 0; p < boms[orders[r].i].p; ++p) {
                Operation& ope = operations[idx];
                if (ope.r < r || ope.p < p) {
                    std::cerr << "分割禁止 : Split operation detected" << std::endl;
                    return 1;
                }
                if (ope.r > r || ope.p > p) {
                    std::cerr << "未割り付け禁止 : Not assigned operation detected" << std::endl;
                    return 1;
                }
                
                if (ope.m != boms[orders[r].i].pTom[p]) {
                    std::cerr << "BOM違反 : BOM violation" << std::endl;
                    return 1;
                }

                if (p == 0 && ope.t1 < orders[ope.r].e) {
                    std::cerr << "製造開始時刻違反 : Scheduling start time violation" << std::endl;
                    return 1;
                }
                if (p != 0 && ope.t1 < prevT2) {
                    std::cerr << "製造開始時刻違反 : Scheduling start time violation" << std::endl;
                    return 1;
                }


                if (ope.t1 < mToPreviousT1[ope.m]) {
                    std::cerr << "作業着手順違反 : Operations assigned to each machine must be in ascending order of order number" << std::endl;
                    return 1;
                }

                if (ope.t1 < mToPreviousT2[ope.m]) {
                    std::cerr << "設備キャパシティ違反 : Machine capacity violation" << std::endl;
                    return 1;
                }

                if (ope.t2 != _t2(orders[ope.r].i, ope.p, orders[ope.r].q, ope.t1)) {
                    std::cerr << "製造時間間違い : Manufacturing time error" << std::endl;
                    return 1;
                }

                prevT2 = ope.t2;
                mToPreviousT1[ope.m] = ope.t1;
                mToPreviousT2[ope.m] = ope.t2;
                ++idx;
            }
        }


        /* 評価 */
        long long grossP = 0;  /* 粗利合計 */
        for (Operation ope : operations) {
            if (ope.p == boms[orders[ope.r].i].p-1 && ope.t2 <= orders[ope.r].d) {
              grossP += orders[ope.r].pr;
            }
        }
        double cost = 0;  /* 能力追加コスト合計 */
        for (Capacity capa : capacities) {
            cost += C[capa.m] * std::pow(capa.ac, 1.1);   
        }
        /* 利益プロフィット(コストの小数点以下は切り上) */
        long long v = static_cast<long long>(grossP - ceil(cost));

        printf("IMOJUDGE<<<%lld>>>\n", v);
        return 0;
    } catch (char* str) {
        std::cerr << "error: " << str << std::endl;
        return 1;
    }
    return 1;
}
