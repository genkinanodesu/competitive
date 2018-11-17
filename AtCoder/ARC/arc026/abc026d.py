class UnionFind:
    def __init__(self, n):
        #親要素のノード番号を格納。par[x] == xのときそのノードはroot
        self.par = [i for i in range(n)]
        #木の高さ（初期状態では0）
        self.rank = [0] * n

    def find(self, x):
        #木の根を求める
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]

    def same(self, x, y):
        # xとyが同じ集合に属するかを判定
        return self.find(x) == self.find(y)

    def union(self, x, y):
        #併合する
        #まず根を探す
        x = self.find(x)
        y = self.find(y)
        if self.rank[x] < self.rank[y]:
            self.par[x] = y
        else:
            self.par[y] = x
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

n, m = map(int, input().split())
edge = [list(map(int, input().split())) for i in range(m)]

def C(x):
    #時給xで修理できるかを判定
    #ci - ti * xでソートし、小さい順に連結していく
    #sum (ci - ti * x) <= 0の間に連結とできるかを判定
    u = UnionFind(n)
    edge.sort(key = lambda y:y[2] - y[3] * x)
    s = 0
    for i in range(m):
        ai, bi, ci, ti = edge[i]
        if (ci - ti * x) < 0:
            s += ci - ti * x
            u.union(ai, bi)
        elif (not (u.same(ai, bi)) and (s + ci - ti * x <= 0)):
            s += ci - ti * x
            u.union(ai, bi)
    for i in range(n-1):
        if not u.same(i, i+1):
            return False
    return True

lb = 0.0
ub = 1000000.0
while (ub - lb > 0.001):
    mid = (lb + ub) / 2
    if (C(mid)):
        ub = mid
    else:
        lb = mid
print(ub)