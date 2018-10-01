N, W = map(int, input().split())
values = []
weights = []
limits = []
for i in range(N):
    item = list(map(int, input().split()))
    values.append(item[0])
    weights.append(item[1])
    limits.append(item[2])

dp = [[0 for w in range(W+1)] for i in range(N+1)]

for i in range(N):
    for w in range(W+1):
        for j in range(limits[i] + 1):
            if w - weights[i] * j >= 0:
                dp[i+1][w] = max(dp[i+1][w], dp[i][w - weights[i] * j] + values[i] * j)
    
print(dp[N][W])
