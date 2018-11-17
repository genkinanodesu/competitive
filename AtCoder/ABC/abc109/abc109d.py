H, W = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(H)]
ans = []
N = 0
for i in range(H):
    for j in range(W - 1):
        if (grid[i][j]) % 2  == 1:
            x = grid[i][j]
            ans.append([i + 1, j + 1, i + 1, j + 2])
            grid[i][j + 1] += 1
            grid[i][j] -= 1
            N += 1

    if i < H - 1 and (grid[i][W - 1]) % 2 == 1:
        y = grid[i][W - 1]
        ans.append([i + 1, W, i + 2, W])
        grid[i][W - 1] -= 1
        grid[i + 1][W - 1] += 1
        N += 1

print(N)
if N > 0:
    for proc in ans:
        y, x, Y, X = proc
        print(y, x, Y, X)


