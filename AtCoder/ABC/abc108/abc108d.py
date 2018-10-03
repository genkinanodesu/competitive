L = int(input())
N = len(bin(L)) - 2 #N: Lの2進法での桁数
nodes = []
for i in range(N - 1):
    u1, v1, w1 = i + 1, i + 2, 0
    u2, v2, w2 = i + 1, i + 2, (1 << i)
    nodes.append([u1, v1, w1])
    nodes.append([u2, v2, w2])
for i in range(1, N):
    if (L >> (i - 1)) & 1 == 1:
        u, v, w = i, N, (L >> i ) << i
        nodes.append([u, v, w])
M = len(nodes)
print(N, M)
for i in range(M):
    u, v, w = nodes[i]
    print(u, v, w)