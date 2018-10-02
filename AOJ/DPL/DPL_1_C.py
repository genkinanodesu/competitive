N, W = map(int, input().split())
items = [list(map(int, input().split())) for i in range(N)]

dp = [[0 for w in range(W+1)] for i in range(N+1)]
for w in range(W+1):
    dp[0][w] = 0
for i in range(N):
    for w in range(W+1):
        if items[i][1] <= w:
            dp[i+1][w] = max(dp[i+1][w-items[i][1]] + items[i][0], dp[i][w])
        else:
            dp[i+1][w] = dp[i][w]
print(dp)
