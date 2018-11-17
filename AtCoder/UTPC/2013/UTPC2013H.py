'''
V, E : Vは頂点数、Eは辺数
nodes : e = [from, to, cost] を要素とする辺のリスト（有向辺）

'''
N, M = map(int, input().split())
p = list(map(int, input().split()))
q = list(map(int, input().split()))
nodes = []
for i in range(N):
    nodes.append([0, i + 1, p[i]])
    nodes.append([i + 1, 0, 0])
    nodes.append([0, i + N + 1, 0])
    nodes.append([i + N + 1, 0, q[i]])
for _ in range(M):
    xk, yk, ak, bk = map(int, input().split())
    nodes.append([xk, yk + N, -ak])
    nodes.append([yk + N, xk, bk])

V = 2 * N + 1
E = len(nodes)

d = [float('inf') for i in range(V)]
d[0] = 0
for _ in range(V):
    update = False
    for i in range(E):
        e = nodes[i]
        if d[e[0]] != float('inf') and d[e[1]] > d[e[0]] + e[2]:
            d[e[1]] = d[e[0]] + e[2]
            update = True
    if not update:
        print('yes')
        exit()
    elif d[0] < 0:
        print('no')
        exit()
print('no')