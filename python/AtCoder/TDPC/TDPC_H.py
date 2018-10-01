N, W, C = map(int, input().split())
item = []

for _ in range(N):
    item.append(list(map(int, input().split())))

item.sort(key = lambda x: x[2])

item[0].append(1) #item[0] = 色1
for i in range(N - 1):
    if item[i + 1][2] > item[i][2]:
        item[i + 1].append(item[i][3] + 1)
    else:
        item[i + 1].append(item[i][3])
#これでitem = [[wi, vi, ci, k] for i in range(N)] ただしkは色の番号　となった

K = item[N - 1][3] #色の種類 K種類
print(item)
dp = [[[[0] * (K + 1) for c in range(C + 1)] for w in range(W + 1)] for i in range(N + 1)]
#dp[w][c][k] = 重さw以下、色c種類以下　ただし色1,2, ..., kのみを使う　という条件
for i in range(N):
    k = item[i][3]
    for c in range(1, C + 1):
        for w in range(0, W + 1):
            if w >= item[i][0]:
                v1 = dp[i][w - item[i][0]][c - 1][k - 1] + item[i][1]
                v2 = dp[i][w - item[i][0]][c][k] + item[i][1]
                v3 = dp[i][w][c][k]
                v4 = dp[i][w][c][k - 1]
                dp[i + 1][w][c][k] = max(v1, v2, v3, v4)
            else:
                dp[i + 1][w][c][k] = max(dp[i][w][c][k], dp[i][w][c][k - 1])

print(dp[N][W][C][K])
