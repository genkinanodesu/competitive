from collections import deque

R, C = map(int, input().split())
sy, sx = map(lambda x: int(x) - 1, input().split())
gy, gx = map(lambda x: int(x) - 1, input().split())
#0<= sy <= R-1, 0<= sx <= C-1
maze = [list(input()) for i in range(R)]
flags = [[-1 for i in range(C)]for j in range(R)]
diffs = [[1, 0], [-1, 0], [0, 1], [0, -1]]

q = deque()
flags[sy][sx] = 0
q.append([sy, sx])
while q:
    v = q.popleft()
    for diff in diffs:
        if 0 <= v[0] + diff[0] <= R - 1 and 0 <= v[1] + diff[1] <= C - 1 and maze[v[0] + diff[0]][v[1] + diff[1]] == '.' and flags[v[0]+diff[0]][v[1]+diff[1]] == -1:
            flags[v[0]+diff[0]][v[1]+diff[1]] = flags[v[0]][v[1]] + 1
            q.append([v[0] + diff[0], v[1] + diff[1]])
print(flags[gy][gx])
