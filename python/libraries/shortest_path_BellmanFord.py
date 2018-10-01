'''
V, E : Vは頂点数、Eは辺数
nodes : e = [from, to, cost] を要素とする辺のリスト（有向辺）

'''

def shortest_path(s):
    '''
    ベルマンフォード法：ループをV回回す→負の辺がなければアルゴリズムは停止 (update = Falseのまま）、あればV回回したあとも更新が続く
    O(|V| * |E|)で計算できる
    :param s: スタート
    :return: 負の辺があればNoneを、なければd = sを始点とする最小距離のリスト　を返す
    '''
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
