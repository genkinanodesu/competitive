V, E = map(int, input().split())

#distance_list[j][i] = 頂点j→iの距離（有向）
distance_list = [[float('inf') for i in range(V)] for j in range(V)]
for i in range(V):
    distance_list[i][i] = 0
for node in range(E):
    start, goal, distance = map(int, input().split())
    distance_list[start][goal] = distance

dp = [[-1 for v in range(V)] for S in range(1 << V)]
def TSP(S, v):
    if dp[S][v] >= 0:
        return dp[S][v]
    else:
        if S == (1 << V) - 1 and v == 0:
            dp[S][v] = 0
            return 0
        else:
            ans = float('inf')
            for u in range(V):
                if (S >> u) & 1 == 0:
                    ans = min(ans, TSP(S | (1 << u), u) + distance_list[v][u])
            dp[S][v] = ans
            return ans
if TSP(0,0) == float('inf'):
    print(-1)
else:
    print(TSP(0,0))
print(dp)
