N, C = map(int, input().split())
#D[X][Y] = (X+1)→(Y+1)に塗り替えたときの違和感
D = [list(map(int, input().split())) for i in range(C)]
#C[i][j] = (i+1,j+1)の色
c = [list(map(int, input().split())) for i in range(N)]
#import pdb; pdb.set_trace()
ans = float('inf')
#c0: (i+1)+(j+1) \equiv 0 なるマスに色1, 色2, ..., 色Cがそれぞれ何個書かれているか
c0 = [0] * C
c1 = [0] * C
c2 = [0] * C
for i in range(N):
    for j in range(N):
        if (i + j) % 3 == 0:
            c0[c[i][j] - 1] += 1
        if (i + j) % 3 == 1:
            c1[c[i][j] - 1] += 1
        if (i + j) % 3 == 2:
            c2[c[i][j] - 1] += 1


for x in range(C):
    for y in range(C):
        for z in range(C):
            if (x-y)*(y-z)*(z-x) != 0:
                iwakan = sum(D[i][x] * c0[i] for i in range(C)) + sum(D[j][y] * c1[j] for j in range(C))+sum(D[k][z] * c2[k] for k in range(C))                
                ans = min(ans, iwakan)
print(ans)
