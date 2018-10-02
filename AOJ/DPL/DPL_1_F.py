N, W = map(int, input().split())
values = []
weights = []
for i in range(N):
    item = list(map(int, input().split()))
    values.append(item[0])
    weights.append(item[1])
max_value = sum(values)

dp = [[float('inf') for value in range(max_value+ 1)] for i in range(N+1)]
dp[0][0] = 0
for i in range(N):
    for value in range(max_value+1):
        if value >= values[i]:
            dp[i+1][value] = min(dp[i][value - values[i]] + weights[i], dp[i][value])
        else:
            dp[i+1][value] = dp[i][value]
for value in range(max_value, 0, -1):
    if dp[N][value] <= W:
        print(value)
        exit()
print(0)
