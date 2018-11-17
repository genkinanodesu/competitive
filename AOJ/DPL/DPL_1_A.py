n, m = map(int, input().split())
coins = list(map(int, input().split()))
dp = [float('inf') for i in range(n+1)]
dp[0] = 0
for i in range(n):
    for coin in coins:
        if coin <= i+1:
            dp[i+1] = min(dp[i+1 - coin] + 1, dp[i+1])
print(dp[n])
