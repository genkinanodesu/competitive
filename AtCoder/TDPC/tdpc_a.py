N = int(input())
p = list(map(int, input().split()))

max_ans = sum(p)
dp = [1] + [0] * max_ans
for i in range(N):
    for j in range(max_ans, -1, -1):
        if j >= p[i]:
            dp[j] = max(dp[j - p[i]], dp[j])
print(sum(dp))
