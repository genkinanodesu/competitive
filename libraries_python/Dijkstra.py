'''
隣接行列を用いた実装
O(V^2) ：次に探す頂点を全探索するため
'''
#V: 頂点数
#cost[i][j] = 辺ijのコスト（重み）

d = [float('inf')] * V
used = [False] * V
prev = [-1] * V

def Dijkstra(s):
    d[s] = 0
    while True:
        v = -1
        for u in range(V):
            if not(used[u]) and (v == -1 or d[u] < d[v]):
                v = u
        if v == -1:
            break
        used[v] = True

        for u in range(V):
            if d[u] > d[v] + cost[v][u]:
                d[u] = d[v] + cost[v][u]
                prev[u] = v

def get_path(s,t):
    Dijkstra(s)
    path = []
    while prev[t] != -1:
        path.append(t)
        t = prev[t]
    return path[::-1]

if __name__ == '__main__':
    V = 7
    cost = [[float('inf')] * V for _ in range(V)]

    for i in range(V):
        cost[i][i] = 0
    cost[0][1] = 2
    cost[0][2] = 5
    cost[1][0] = 2
    cost[1][2] = 4
    cost[1][3] = 6
    cost[1][4] = 10
    cost[2][0] = 5
    cost[2][1] = 4
    cost[2][3] = 2
    cost[3][1] = 6
    cost[3][2] = 2
    cost[3][5] = 1
    cost[4][1] = 10
    cost[4][5] = 3
    cost[4][6] = 5
    cost[5][3] = 1
    cost[5][4] = 3
    cost[5][6] = 9
    cost[6][4] = 5
    cost[6][5] = 9
    print(get_path(0, 6))
    print

