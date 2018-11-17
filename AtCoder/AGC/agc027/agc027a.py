import bisect
N, x = map(int, input().split())
a = sorted(list(map(int, input().split())))
s = sum(a)
if x > s:
    print(N - 1)
elif s == x:
    print(N)
else:
    a_cum = [0] * (N + 1)
    for i in range(N):
        a_cum[i + 1] = a_cum[i] + a[i]
    ans = bisect.bisect_right(a_cum, x)
    print(ans - 1)
