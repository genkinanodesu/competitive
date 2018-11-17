'''
隣接リストを用いた実装
O(ElogV) ：次に探す頂点をプライオリティーキューを用いて探索
V: 頂点数
G[i] = [(j, c_ij) for j in (iに隣接する頂点）]
'''
import heapq

def Dijkstra(G, start):
    d = [float('inf')] * V
    d[start] = 0
    q =[]
    heapq.heappush(q, (0, start))
    while len(q) > 0:
        dist, v  = heapq.heappop(q)
        if d[v] < dist:
            continue
        for j, cost in G[v]:
            if d[j] > d[v] + cost:
                d[j] = d[v] + cost
                heapq.heappush(q, (d[j], j))
    return d

V, E, s, t = map(int, input().split())
Yen = [[] for _ in range(V)]
Snuke = [[] for _ in range(V)]
for i in range(E):
    ui, vi, ai, bi = map(int, input().split())
    Yen[ui - 1].append((vi - 1, ai))
    Yen[vi - 1].append((ui - 1, ai))
    Snuke[ui - 1].append((vi - 1, bi))
    Snuke[vi - 1].append((ui - 1, bi))

Yen_min = Dijkstra(Yen, s - 1)
Snuke_min = Dijkstra(Snuke, t - 1)
dist = [(Yen_min[i] + Snuke_min[i]) for i in range(V)]
ans = [float('inf') for i in range(V)]
ans[V - 1] = dist[V - 1]
for i in range(V - 2, -1, -1):
    ans[i] = min(dist[i], ans[i + 1] )
for i in range(V):
    print(10 ** 15 - ans[i])