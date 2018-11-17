N, M = map(int, input().split())
p = list(map(int, input().split()))

par = [i for i in range(N)]
def root(x):
    if par[x] == x:
        return x
    else:
        par[x] = root(par[x])
        return par[x]

def same(x, y):
    return root(x) == root(y)

def unite(x, y):
    x = root(x)
    y = root(y)
    if x == y:
        pass
    else:
        par[x] = y

for i in range(M):
    xi, yi = map(int, input().split())
    unite(xi - 1, yi - 1)

ans = 0
for i in range(N):
    if same(i, p[i] - 1):
       ans += 1
print(ans)