N, W, C = map(int, input().split())

weights = []
values = []
color = []
for _ in range(N):
    wi, vi, ci = map(int, input().split())
    weights.append(wi)
    values.append(vi)
    color.append(ci)

dp = [[[[0] * (2 * C) for c in range(C)] for w in range(W + 1)] for i in range(N + 1)]

for i in range(N):
    for w in range(W + 1):
        for c in range(1, C + 1):
            if w >= weights[i]:
                v1 = dp[i][w - weights[i]][c - 1][color[i] + C - 1] + value[i]
                v2 = dp[i][w - weights[i]][c][color[i] - 1] + value[i]
                v3 = dp[i][w][c][color[i] - 1]
                v4 = dp[i][w][c][color[i] - 1]
                dp[i + 1][w][c][color[i] - 1] = max(v1, v2, v3, v4)
                dp[i + 1][w][c][color[i] +  C - 1] = dp[i + 1][w][c][color[i] + C - 1]
                for j in range(2 * C):
                    if j != color[i] - 1 and J != color[i] + C - 1:
                        dp[i + 1][w][c][j] = max(dp[i][w - weight[i]][c][j] + value