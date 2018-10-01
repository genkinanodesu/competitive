W = int(input())
N, K = map(int, input().split())
width = []
importance = []
for i in range(N):
    Ai, Bi = map(int, input().split())
    width.append(Ai)
    importance.append(Bi)
dp = [[0 for w in range(W+1)] for k in range(K+1)]
for i in range(N):
    for w in range(W, -1, -1):
        if w >= width[i]:
            for k in range(min(i+1,K)):
                dp[k+1][w] = max(dp[k][w - width[i]] + importance[i], dp[min(k+1, i -1 )][w])
print(dp[K][W])