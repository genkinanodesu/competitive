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

N, Q = map(int, input().split())

#街iはtowns[i]およびtowns[i + N]に対応
towns = UnionFind(2 * N)
answers = []
for k in range(Q):
    wi, xi, yi, zi = map(int, input().split())
    if wi == 1:
        if zi % 2 == 0:
            towns.union(xi - 1, yi - 1)
            towns.union(xi - 1 + N, yi - 1 + N)
        else:
            towns.union(xi - 1, yi - 1 + N)
            towns.union(xi - 1 + N, yi - 1)
    else:
        answers.append('YES' if towns.same(xi - 1, yi - 1) else 'NO')
for ans in answers:
    print(ans)
