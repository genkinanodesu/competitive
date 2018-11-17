D, F, T, N = map(int, input().split())
X = [0] + list(map(int, input().split())) + [D]
mod = 10 ** 9 + 7

l = [0] * (N + 1)
r = [0] * (N + 1)
left = 0
right = 0
for i in range(N + 1):
    while left <= N and not (X[i] + F - T < X[left]):
        left += 1
    l[i] = left
    while right <= N + 1 and not (X[i] + F < X[right]):
        right += 1
    r[i] = right

dp = [-1] * (N + 2)
dp[N + 1] = 1
dp_accum = [0] * (N + 3)  #dp_accum[i] = dp[i] + ... + dp[N + 1]
dp_accum[N + 1] = 1

for i in range(N, -1, -1):
    li, ri = l[i], r[i]
    dp[i] = (dp_accum[l[i]] - dp_accum[r[i]] ) * pow(2, l[i] - i - 1, mod) % mod
    dp_accum[i] = (dp[i] + dp_accum[i + 1]) % mod
print(dp[0])
