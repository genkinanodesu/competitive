V, E, r = map(int, input().split())
nodes = [list(map(int, input().split())) for _ in range(E)] #e = from, to, cost

def shortest_path(s):
    d = [float('inf') for i in range(V)]
    d[s] = 0
    for _ in range(V):
        update = False
        for i in range(E):
            e = nodes[i]
            if d[e[0]] != float('inf') and d[e[1]] > d[e[0]] + e[2]:
                d[e[1]] = d[e[0]] + e[2]
                update = True
    if update:
        return None
    else:
        return d

if not shortest_path(r):
    print('NEGATIVE CYCLE')
else:
    d = shortest_path(r)
    for i in range(V):
        if d[i] == float('inf'):
            print('INF')
        else:
            print(d[i])
