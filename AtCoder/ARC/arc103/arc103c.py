import collections
n = int(input())
v = list(map(int, input().split()))

v0 = collections.Counter([v[2 * i] for i in range(n // 2)])
v1 = collections.Counter([v[2 * i + 1] for i in range(n // 2)])

if v0.most_common()[0][0] != v1.most_common()[0][0]:
    ans = n - v0.most_common()[0][1] - v1.most_common()[0][1]
else:
    if len(v0) == 1:
        if len(v1) == 1:
            ans = n // 2
        else:
            ans = n - v1.most_common()[1][1]
    else:
        if len(v1) == 1:
            ans = n - v0.most_common()[1][1]
        else:
            ans = min(n - v0.most_common()[0][1] - v1.most_common()[1][1], n - v0.most_common()[1][1] - v1.most_common()[0][1])

print(ans)