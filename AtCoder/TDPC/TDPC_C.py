def prob(x, y):
    #rating x と y が対戦したときのxの勝率
    return 1 / (1 + 10 ** ((y - x) / 400) )


K = int(input())
rate = [int(input()) for _ in range(1 << K)]

dp = [[1] * (1 << K) for _ in range(K + 1)]
#dp[k][i] = (k回戦でiが勝つ確率) ただしdp[0][i] = 1
for k in range(K):
    for i in range(1 << K):
        s = ((i >> k) ^ 1) << k
        t = (((i >> k) ^ 1) + 1) << k
        dp[k + 1][i] = sum([dp[k][i] * dp[k][j] * prob(rate[i], rate[j]) for j in range(s, t, 1)])

for i in range(1 << K):
    print('{:.8f}'.format(dp[K][i]))