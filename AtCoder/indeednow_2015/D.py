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

H, W = map(int, input().split())
Sx, Sy = map(int, input().split())
Gx, Gy = map(int, input().split())
grid = [list(map(int, input().split())) for i in range(H)]
nodes = []
for i in range(W - 1):
    for j in range(H):
        gain = grid[j][i] * grid[j][i + 1]
        nodes.append([gain, i + j * W, i + 1 + j * W])

for i in range(W):
    for j in range(H - 1):
        gain = grid[j][i] * grid[j + 1][i]
        nodes.append([gain, i + j * W, i + (j + 1) * W])

tree = UnionFind(H * W)
bonus = 0
nodes.sort()
for node in nodes[::-1]:
    if not tree.same(node[1], node[2]):
        bonus += node[0]
        tree.union(node[1], node[2])

total = sum([sum(grid[i]) for i in range(H)])

print(total + bonus)