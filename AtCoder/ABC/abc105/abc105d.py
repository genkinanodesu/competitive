from collections import Counter

N, M = map(int, input().split())
A = [int(x) for x in input().split()]
accum = [0 for i in range(N + 1)] #累積和
for i in range(N):
    accum[i + 1] = (accum[i] + A[i]) % M
accum.sort()
c = Counter(accum)
ans = 0
for val in c.values():
    if val > 1:
        ans += val * (val - 1) // 2
print(ans)