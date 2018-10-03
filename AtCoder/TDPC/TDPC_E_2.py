
D = int(input())
N = input()
L = len(N)
mod = 1000000007
dp = [[[0] * 2 for i in range(D)] for k in range(L + 1)]
dp[0][0][1] = 1
for k in range(L):
    for i in range(D):
        x = dp[k][i][0]
        y = dp[k][i][1]
        for j in range(10):
            dp[k + 1][(i + j) % D][0] = (dp[k + 1][(i + j) % D][0] + x) % mod
        for j in range(0, int(N[k])):
            dp[k + 1][(i + j) % D][0] = (dp[k + 1][(i + j) % D][0] + y) % mod
        j = int(N[k])
        dp[k + 1][(i + j) % D][1] = (dp[k + 1][(i + j) % D][1] + y) % mod

print(int((dp[L][0][0] + dp[L][0][1] - 1) % mod))