import heapq

V, E, start = map(int, input().split())
G = [[] for _ in range(V)]
for i in range(E):
    si, ti, di = map(int, input().split())
    G[si].append((ti, di))

d = [float('INF')] * V
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

Dijkstra(start)
for i in range(V):
    if d[i] == float('inf'):
        print('INF')
    else:
        print(d[i])
