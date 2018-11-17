from collections import Counter
class UnionFind:
    #Union Find木のクラス

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

    def same(x, y):
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


N, K, L = map(int, input().split())
road = UnionFind(N)
rail = UnionFind(N)

for i in range(K):
    pi, qi = map(lambda x: int(x) - 1, input().split())
    road.union(pi, qi)

for i in range(L):
    ri, si = map(lambda x: int(x) - 1, input().split())
    rail.union(ri, si)


road_and_rail = [(road.find(i), rail.find(i)) for i in range(N)]
count = Counter(road_and_rail)

ans = []
for i in range(N):
    ans.append(str(count.get(road_and_rail[i])))
print(' '.join(ans))