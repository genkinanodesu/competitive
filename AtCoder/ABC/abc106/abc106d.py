import bisect

N, M, Q = map(int, input().split())
trains = [list(map(int, input().split())) for i in range(M)]
queries = [list(map(int, input().split())) for i in range(Q)]

A  =[[0] * N for _ in range(N)] #A[i][j] = (i + 1) -> (j+1)なる列車の本数
for train in trains:
    li, ri = train
    A[li - 1][ri - 1] += 1
dp = [[0] * N for _ in range(N)]
reached = [[False] * N for _ in range(N)]
def ans(left, right):
    if reached[left][right]:
        return dp[left][right]
    elif left > right:
        return 0
    elif left == right:
        dp[left][right] = A[left][right]
        reached[left][right] = True
        return A[left][right]
    else:
        dp[left][right] = ans(left, right-1) + ans(left + 1, right) + A[left][right] - ans(left + 1, right - 1)
        reached[left][right] = True
        return dp[left][right]

for q in range(Q):
    pi, qi = queries[q]
    print(ans(pi - 1, qi - 1))

