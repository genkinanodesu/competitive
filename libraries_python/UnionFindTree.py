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

