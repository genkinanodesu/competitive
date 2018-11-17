N = int(input())
grid = []
for _ in range(N):
    xi, yi =map(int, input().split())
    grid.append([xi, yi])

a = (grid[0][0] + grid[0][1]) % 2
for i in range(N):
    if (grid[i][0] + grid[i][1] ) % 2 != a:
        print(-1)
        exit()

subset_case = True

for i in range(N):
    if abs(grid[i][0]) > 10 or abs(grid[i][1]) > 10:
        subset_case = False

if subset_case:
    m = 0
    for i in range(N):
        m = max(m, abs(grid[i][0]) + abs(grid[i][1]))
    arm = [1] * m
    ans = []
    for i in range(N):
        xi, yi = grid[i]
        if xi >= 0:
            r = xi
            l = 0
            u = (m - xi + yi) // 2
            d = (m - xi - yi) // 2
        else:
            r = 0
            l = abs(xi)
            u = (m + xi + yi) // 2
            d = (m + xi - yi) // 2
        st = 'R' * r + 'L' * l + 'U' * u + 'D' * d
        ans.append(st)
    print(m)
    print(' '.join(map(str, arm)))
    for i in range(N):
        print(ans[i])