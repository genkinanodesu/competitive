N, K = map(int, input().split())
A = list(map(int, input().split()))
mod = 10 ** 9 + 7

def digit_2 (x):
    if x == 0:
        return 0
    else:
        return len(bin(x)) - 2

B = [digit_2(a) for a in A]
p = 1
q = 1
for b in B:
    p = p * (b + 1) % mod
    q = q * b % mod
#prod = Pi _{b in B} (b + 1)

dp1 = [[0] * (sum(B) + 1) for _ in range(N + 1)]
dp2 = [[0] * (sum(B) + 1) for _ in range(N + 1)]
'''
dp1[i][k] = x1 + x2 + ... + xi = k xj>= bjは同一視、の解の個数
dp2[i][k] = x1 + x2 + ... + xi <= k 各xj <= bj の解の個数
'''

dp1[0][0] = 1
dp2[0] = [1] * (sum(B) + 1)
for i in range(N):
    for k in range(sum(B) + 1):
        dp2[i + 1][k] = sum(dp2[i][max(0, k - B[i]): k + 1]) % mod
        if k >= B[i]:
            dp1[i + 1][k] = (sum(dp1[i][k - B[i] + 1: k + 1]) + dp2[i][k - B[i]]) % mod
        else:
            dp1[i + 1][k] = sum(dp1[i][0: k + 1]) % mod

if K >= sum(B):
    print((p - q) % mod)
else:
    print(dp1[N][K])