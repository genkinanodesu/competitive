'''
d[u][v] = 辺e = (u, v) のコスト　で初期化
V: 頂点数
'''

def warshall_floyd(d):
    for k in range(V):
        for i in range(V):
            for j in range(V):
                d[i][j] = min(d[i][j], d[i][k] + d[k][j])
    return d
