N, Q = map(int, input().split())
queries = [list(map(int, input().split())) for i in range(Q)]
#要素数NのUnion-Find木の実装
par = [i for i in range(N)]
rank = [0 for i in range(N)]
def find(x): #木の根を求める
    if par[x] == x:
        return x
    else:
        par[x] = find(par[x])
        return par[x]

def unite(x, y): #xとyの属する集合を併合
    x = find(x)
    y = find(y)
    if x == y:
        pass
    else:
        if rank[x] < rank[y]:
            par[x] = y
        else:
            par[y] = x
            if rank[x] == rank[y]:
                rank[x] += 1
def same(x, y): #xとyが同じ集合に属するか否か
    return find(x) == find(y)

for query in queries:
    pi, ai, bi = query[0], query[1] - 1, query[2] - 1
    if pi == 0:
        unite(ai, bi)
    else:
        if same(ai, bi):
            print('Yes')
        else:
            print('No')