'''
max(効用) - min(効用)の最小値がdである
<->
「すべてのiについてl <= 効用 <= l + dが成り立つようなlが存在する」…☆
ようなdの最小値を求める
各iについてl <= (Ai - Bi) * xi + Bi* Z <= l + d となるxiの範囲の下限lb_i、上限ub_iを求める
ただし0<= xi <= Zの範囲
解なしならlb_i = ub_i = -1
sum(lb_i) <= X <= sum(ub_i) ならOK


計算量：dの候補は0からmax(A, B) * Z（甘めの評価）→2分探索にはlog (10 ** 9 * 10 ** 5) = log(10 ** 14) <= 50くらい
→1回の探索あたりO(10 ** 5)くらいが上限、つまりO(X)が上限

'''

X, Y, N = map(int, input().split())
Z = (X + Y ) // N
A = []
B = []
for i in range(N):
    Ai, Bi = map(int, input().split())
    A.append(Ai)
    B.append(Bi)

def utility(i, x):
    # i番目の人がオレンジをx個もらったときの満足度
    return (A[i] - B[i]) * x + B[i] * Z

def linear_ineq(a, b, c, d):
    #c <= ax + b <= d かつ 0<= x <= Zを満たすようなxの範囲[u, l]を返す　ただし解なしのときは[-1, -1]を返す
    if a > 0:
        u = (c - b + a - 1) // a
        l = (d - b) // a
        if l < 0 or Z < u:
            return [-1, -1]
        else:
            return [max(0, u), min(l, Z)]
    elif a < 0:
        return linear_ineq(-a, -b, -d, -c)
    else:
        if c <= b <= d:
            return [0, Z]
        else:
            return [-1, -1]

def solve(d):
    #dをfixしたときに、☆が成立するかを調べる
    #まずl = 0での様子を調べる
    bad = 0
    sum_lb = 0
    sum_ub = 0
    for i in range(N):
        lb, ub = linear_ineq(A[i] - B[i], B[i] * Z, 0, d)
        if lb == -1:
            bad += 1
        sum_lb += lb
        sum_ub += ub
    L = []
    for x in range(Z + 1):
        for i in range(N):
            L += [[utility(i, x), x, i, 0], [utility(i, x) - d - 1, x, i, 1]]
    L.sort(key = lambda x: x[0])
    #L: bad, sum_lb, sum_ub が更新される可能性があるlの集合　ソート済み [l, x, i, 0 or 1]を値に持つ
    for k in range(N * (Z + 1) * 2):
        l, x, i, bool = L[k]
        if 0 <= l:
            if A[i] > B[i]:
                if bool == 0:
                    if x == Z:
                        bad += 1
                        sum_lb -= (Z + 1)
                        sum_ub -= (Z + 1)
                    else:
                        sum_lb += 1
                else:
                    if x == 0:
                        bad -= 1
                        sum_lb += 1
                        sum_ub += 1
                    else:
                        sum_ub += 1
            else:
                if bool == 0:
                    if x == 0:
                        bad += 1
                        sum_lb -= 1
                        sum_ub -= 1
                    else:
                        sum_ub -= 1
                else:
                    if x == Z:
                        bad -= 1
                        sum_lb += Z + 1
                        sum_ub += Z + 1
                    else:
                        sum_lb -= 1
            if k == 2 * N * (Z + 1) - 1 or l < L[k + 1][0]:
                #値の更新が終わったとき
                if bad <= 0 and sum_lb <= X <= sum_ub:
                    return True
    return False

M = max(max(A), max(B))
for i in range(M * Z + 1):
    if solve(i):
        print(i)
        exit()
