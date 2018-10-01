import numpy as np
H, W, D = map(int, input().split())
grid = np.array([[0, 0]] * (H * W))
for i in range(H):
    Ai = list(map(int, input().split()))
    for j in range(W):
        grid[Ai[j] - 1] = [i, j]
Q = int(input())
tasks = [list(map(int, input().split())) for _ in range(Q)]

accum = [0] * (H*W)
for i in range(H * W):
    if i >= D:
        accum[i] = accum[i - D] + abs(grid[i][0] - grid[i - D][0]) + abs(grid[i][1] - grid[i - D][1])

for q in range(Q):
    Li, Ri = tasks[q]
    print(accum[Ri - 1] - accum[Li - 1])
