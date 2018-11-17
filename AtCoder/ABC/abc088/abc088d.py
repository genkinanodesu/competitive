from collections import deque
H, W = map(int, input().split())
grid = [list(input()) for i in range(H)]
flag = [[-1 for i in range(W)] for j in range(H)]
whites = sum(grid[i].count('.') for i in range(H))
#BFS
q = deque()
q.append([0,0])
flag[0][0] = 0
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
while q:
    v = q.popleft()
    for j in range(4):
        if 0 <= v[0] + dx[j] < H and 0 <= v[1] + dy[j] < W and grid[v[0]+dx[j]][v[1]+dy[j]] == '.' and flag[v[0]+dx[j]][v[1]+dy[j]] == -1:
            flag[v[0]+dx[j]][v[1]+dy[j]] = flag[v[0]][v[1]] + 1
            q.append([v[0]+dx[j], v[1]+dy[j]])
if flag[H-1][W-1] == -1:
    print(-1)
else:
    print(whites - flag[H-1][W-1] - 1)
