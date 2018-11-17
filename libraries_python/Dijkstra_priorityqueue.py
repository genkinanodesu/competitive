'''
隣接リストを用いた実装
O(ElogV) ：次に探す頂点をプライオリティーキューを用いて探索
V: 頂点数
G[i] = [(j, c_ij) for j in (iに隣接する頂点）]
'''
import heapq
V = 7
d = [float('inf')] * V
used = [False] * V
prev = [-1] * V

def Dijkstra(s):
    d[s] = 0
    q =[]
    heapq.heappush(q, (0, s))
    while len(q) > 0:
        dist, v  = heapq.heappop(q)
        if d[v] < dist:
            continue
        for j, cost in G[v]:
            if d[j] > d[v] + cost:
                d[j] = d[v] + cost
                heapq.heappush(q, (d[j], j))
                prev[j] = v

def get_path(s,t):
    Dijkstra(s)
    path = []
    while prev[t] != -1:
        path.append(t)
        t = prev[t]
    return path[::-1]

if __name__ == '__main__':
    V = 7
    G = [[] for _ in range(V)]
    G[0] = [(1, 2), (2, 5)]
    G[1] = [(0, 2), (2, 4), (3, 6), (4, 10)]
    G[2] = [(0, 5), (1, 4), (3, 2)]
    G[3] = [(1, 6), (2, 2), (5, 1)]
    G[4] = [(1, 10), (5, 3), (6, 5)]
    G[5] = [(3, 1), (4, 3), (6, 9)]
    G[6] = [(4, 5), (5, 9)]
    print(get_path(0, 6))
    print(d)

