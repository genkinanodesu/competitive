A, B= map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

a_cum = [0] * (A + 1)
b_cum = [0] * (B + 1)
for i in range(A-1, -1, -1):
    a_cum[i] = a_cum[i + 1] + a[i]
for j in range(B - 1, -1, -1):
    b_cum[j] = b_cum[j + 1] + b[j]
#a_cum[i] = sum(A[i:]), b_cum[j] = sum(B[j:])

dp = [[0] * (B + 1) for _ in range(A + 1)]
for i in range(A, -1, -1):
    for j in range(B, -1, -1):
        if i < A and j < B:
            x = a_cum[i + 1] + b_cum[j] + a[i] - dp[i + 1][j]
            y = a_cum[i] + b_cum[j + 1] + b[j] - dp[i][j + 1]
            dp[i][j] = max(x, y)
        elif i == A and j < B:
            dp[i][j] = a_cum[i] + b_cum[j + 1] + b[j] - dp[i][j + 1]
        elif i < A and j == B:
            dp[i][j] = a_cum[i + 1] + b_cum[j] + a[i] - dp[i + 1][j]

print(dp[0][0])
