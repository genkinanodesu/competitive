'''
V, E : Vは頂点数、Eは辺数
nodes : e = [from, to, cost] を要素とする辺のリスト（有向辺）
☆負のループがあっても、それがゴールと非連結な場所にあった場合関係ない。
つまり「0→負のループ→N-1」という経路が存在するときのみ問題になる。
0→負のループ、という経路があるかどうかは0からの距離がfloat('inf')でないことで調べられる
負のループのある点→N-1という経路があるかどうかは、更新の際にnegative[i]から辺が伸びている頂点も更新することで調べられる。
'''
V, E = map(int, input().split())
nodes = []
for _ in range(E):
    e_from, e_to, e_cost = map(int, input().split())
    e_from -= 1
    e_to -= 1 #頂点を0-indexedに
    e_cost *= -1
    nodes.append([e_from, e_to, e_cost])

d = [float('inf')] * V
negative = [False] * V
d[0] = 0
for _ in range(V):
    update = True
    for e in nodes:
        if d[e[0]] != float('inf') and d[e[1]] > d[e[0]] + e[2]:
            d[e[1]] = d[e[0]] + e[2]
            update = False
    if update:
        print(- d[V - 1])
        exit()

for _ in range(V):
    for e in nodes:
        if d[e[0]] != float('inf') and d[e[1]] > d[e[0]] + e[2]:
            d[e[1]] = d[e[0]] + e[2]
            negative[e[1]] = True
        if negative[e[0]]:
            negative[e[1]] = True

if negative[V - 1]:
    print('inf')
else:
    print(- d[V - 1])