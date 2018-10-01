N, W = map(int, input().split())
values = []
weights = []
for i in range(N):
    vi, wi = map(int, input().split())
    values.append(vi)
    weights.append(wi)

dp = [[-1 for _ in range(W + 1)] for i in range(N + 1)]

#(v_i, w_i), (v_(i+1), w_(i+1))...(v_(N-1), w_(N-1))から重さj以下となるように選ぶ
def knapsack(i, j):
    if dp[i][j] >= 0 :
        return dp[i][j]
    else:
        ans = 0
        if i == N:
            ans = 0
        elif j < weights[i]:
            ans = knapsack(i + 1, j)
        else:
            ans = max(knapsack(i + 1, j), knapsack(i + 1, j - weights[i]) + values[i])
        dp[i][j] = ans
        return ans

print(knapsack(0, W))