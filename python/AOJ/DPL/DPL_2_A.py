V, E = map(int, input().split())

#distance_list[j][i] = 頂点j→iの距離（有向）
distance_list = [[float('inf') for i in range(V)] for j in range(V)]
for i in range(V):
    distance_list[i][i] = 0
for node in range(E):
    start, goal, distance = map(int, input().split())
    distance_list[start][goal] = distance

dp = [[-1 for bit in range(1<< V)] for v in range(V)]
def TSP(S, v):
    if dp[S][v] >= 0:
        return dp[S][v]
    elif S == (1 << V - 1) and v == 0:
        dp[S][v] = 0
        return 0
    else:
        res = float('inf')
        for u in range(V):
            if  (S >> u) & 1 == 0:
                res = min(res, TSP((S | 1 <<  u),u) + distance_list[v][u])
        dp[S][v] = res
        return res

print(dp[0][0])

'''
頂点の訪問順を全探索　O(N!)

import itertools

V, E = map(int, input().split())

#distance_list[j][i] = 頂点j→iの距離（有向）
distance_list = [[float('inf') for i in range(V)] for j in range(V)]
for i in range(V):
    distance_list[i][i] = 0
for node in range(E):
    start, goal, distance = map(int, input().split())
    distance_list[start][goal] = distance

min_route = float('inf')

#この部分は要修正
for route in itertools.permutations(range(1, V, 1)):
    length = distance_list[0][route[0]]

    while length < float('inf') and i <= V - 1:
        length += distance_list[route[i]][route[(i+1)%V]]
        i +=  1
    min_route = min(min_route, length)

if min_route == float('inf'):
    print(-1)
else:
    print(min_route)
'''
