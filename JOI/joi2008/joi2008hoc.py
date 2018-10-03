import bisect

N, M = map(int, input().split())
scores = [0] + [int(input()) for _ in range(N)]

s2 = set()
for i in range(N + 1):
    for j in range(i, N + 1, 1):
        if scores[i] + scores[j] <= M:
            s2.add(scores[i] + scores[j])
l2 = sorted(list(s2))

ans = 0
for s in l2:
    if s <= M:
        i = bisect.bisect_right(l2, M - s)
        ans = max(ans, s + l2[i - 1])
print(ans)