V, E = map(int, input().split())

#distance_list[j][i] = 頂点j→iの距離（有向）
distance_list = [[float('inf') for i in range(V)] for j in range(V)]
for i in range(V):
    distance_list[i][i] = 0
for node in range(E):
    start, goal, distance = map(int, input().split())
    distance_list[start][goal] = distance

dp = [[float('inf') for v in range(V)] for S in range(1 << V)]
dp[(1 << V) - 1][0] = 0
for S in range((1 << V) - 2, -1, -1):
    for v in range(V):
        for u in range(V):
            if (S >> u ) & 1 == 0:
                dp[S][v] = min(dp[S][v], dp[S | 1 << u][u] + distance_list[v][u])

if dp[0][0] ==float('inf'):
    print(-1)
else:
    print(dp[0][0])
print(dp)
