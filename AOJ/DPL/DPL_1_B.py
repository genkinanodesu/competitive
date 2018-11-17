N, W = map(int, input().split())
# [(v_i, w_i) for i in range(N)] v_i:value w_i: weight
items = [list(map(int, input().split())) for i in range(N)]

#dp[j][i] = j個の荷物を重さi以下になるように詰め込んだときの価値の最大値
dp = [[-float('inf') for i in range(W+1)] for j in range(N+1)]
for i in range(W+1):
    dp[0][i] = 0
for j in range(N):
    for w in range(W+1):
        if items[j][1] <= w:
            dp[j+1][w] = max(dp[j][w-items[j][1]] + items[j][0], dp[j][w])
        else:
            dp[j+1][w] = dp[j][w]

print(dp[N][W])
                    
        
