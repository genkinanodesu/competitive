import sys
sys.setrecursionlimit(1000000)

N, M, R = map(int, input().split())
dest = list(map(int, input().split())) #訪れないと行けない街r1, r2, ..., rR

d = [[float('inf')] * N for _ in range(N)]
for i in range(N):
    d[i][i] = 0
for _ in range(M):
    A, B, C = map(int, input().split())
    d[A - 1][B - 1] = C
    d[B - 1][A - 1] = C

#ワーシャルフロイト法
#d[i][j]はi→jの最短経路長
for k in range(N):
    for i in range(N):
        for j in range(N):
            d[i][j] = min(d[i][j], d[i][k] + d[k][j])

c = [[d[dest[i] - 1][dest[j] - 1] for j in range(R)] for i in range(R)]

dp_memo = [[float('inf')] * R for _ in range(1 << R)]

def TSP(T, v):
    #今まで訪れた頂点の集合：T　今いる頂点：vとしたときの残りを全部巡回する最短の長さ

    if dp_memo[T][v] != float('inf'):
        return dp_memo[T][v]

    elif T == (1 << R) - 1 :
        #全部訪れたとき
        dp_memo[T][v] = 0
        return 0
    else:
        res = float('inf')
        for u in range(R):
            if (T >> u) & 1 == 0:
                res = min(res, TSP(T | (1 << u), u) + c[v][u])
        dp_memo[T][v] = res
        return res

ans = float('inf')
for i in  range(R):
    ans = min(ans, TSP(0, i))
print(ans)