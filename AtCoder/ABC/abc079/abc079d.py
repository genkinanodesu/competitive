H, W = map(int, input().split())
d = [list(map(int, input().split())) for _ in range(10)]
for k in range(10):
    for i in range(10):
        for j in range(10):
            d[i][j] = min(d[i][j], d[i][k] + d[k][j])

wall = [list(map(int, input().split())) for _ in range(H)]
ans = 0
for i in range(H):
    for j in range(W):
        if wall[i][j] >= 0:
            num = wall[i][j]
            ans += d[num][1]

print(ans)