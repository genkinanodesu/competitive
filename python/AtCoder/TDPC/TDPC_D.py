import numpy as np
N, D = map(int, input().split())

ord_2 = 0
ord_3 = 0
ord_5 = 0

while D > 1:
    if D % 2 == 0:
        ord_2 += 1
        D //= 2
    elif D % 3 == 0:
        ord_3 += 1
        D //= 3
    elif D % 5 == 0:
        ord_5 += 1
        D //= 5
    else:
        print(0)
        exit()

dp = np.zeros([N + 1, ord_2 + 1, ord_3 + 1, ord_5 + 1])
dp[0, 0, 0, 0] = 1
for i in range(N):
    for x in range(ord_2 + 1):
        for y in range(ord_3 + 1):
            for z in range(ord_5 + 1):
                X = min(x + 1, ord_2)
                XX = min(x + 2, ord_2)
                Y = min(y + 1, ord_3)
                Z = min(z + 1, ord_5)
                p = dp[i, x, y, z]
                dp[i + 1, x, y, z] += p * (1 / 6) # 1が出たとき
                dp[i + 1, X, y, z] += p * (1 / 6) # 2が出たとき
                dp[i + 1, x, Y, z] += p * (1 / 6) # 3が出たとき
                dp[i + 1, XX, y, z] += p * (1 / 6) # 4が出たとき
                dp[i + 1, x, y, Z] += p * (1 / 6) # 5が出たとき
                dp[i + 1, X, Y, z] += p * (1 / 6) # 6が出たとき

print('{:.8f}'.format(dp[N, ord_2, ord_3, ord_5]))