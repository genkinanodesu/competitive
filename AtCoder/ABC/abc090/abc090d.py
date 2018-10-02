N, K = map(int, input().split())
ans = 0
if K == 0:
    print(N * N)
else:
    for a in range(K + 1, N + 1):
        ans += (N// a) * (a - K) + max(N % a - K + 1, 0)
    print(ans)
