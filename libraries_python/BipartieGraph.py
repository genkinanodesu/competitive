'''
G: 頂点数Vのグラフ（隣接リストによる表現）
G[i] = (iと隣接している頂点)
color[i]: 頂点iの色 +1 or -1
Gが2部グラフか否かを判定する
'''
V  = int(input())
G = [list(map(int, input().split())) for _ in range(V)]
color = [0 for i in range(V)]

def dfs(v, c):
    '''
    頂点vをcで塗る　そこから深さ優先探索で交互に塗っていく
    '''
    color[v] = c
    for i in G[v]:
        if color[i] == c:
            return False
        if color[i] == 0 and not(dfs(i, -c)):
            return False
    return True

def BipartieGraph():
    for i in range(V):
        if color[i] == 0 and not(dfs(i, 1)):
            return False
    else:
        return True

print(BipartieGraph())