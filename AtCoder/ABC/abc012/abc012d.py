N, M = map(int, input().split())
d = [[float('inf')] * N for _ in range(N)]
for i in range(N):
    d[i][i] = 0

for _ in range(M):
    ai, bi, ti = map(int, input().split())
    d[ai - 1][bi - 1] = ti
    d[bi - 1][ai - 1] = ti

for k in range(N):
    for i in range(N):
        for j in range(N):
            d[i][j] = min(d[i][j], d[i][k] + d[k][j])
ans = float('inf')
for i in range(N):
    ans = min(ans, max(d[i]))
print(ans)