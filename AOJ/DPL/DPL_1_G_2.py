N, W = map(int, input().split())
values = []
weights = []
limits = []
for i in range(N):
    item = list(map(int, input().split()))
    values.append(item[0])
    weights.append(item[1])
    limits.append(item[2])
max_value = sum([values[i] * limits[i] for i in range(N)])

dp = [[float('inf') for v in range(max_value+1)] for i in range(N+1)]
dp[0][0] = 0

for i in range(N):
    for v in range(max_value + 1):
        for j in range((limits[i] + 1)):
            if v - values[i] * j >= 0:
                dp[i+1][v] = min(dp[i+1][v], dp[i][v - values[i] * j] + weights[i] * j)
for v in range(max_value, -1, -1):
    if dp[N][v] <= W:
        print(v)
        exit()
