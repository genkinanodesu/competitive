n = int(input())
a = sorted(list(map(int, input().split())))

m = a[-1] / 2
ans = 0
for i in range(n - 1):
    if abs(a[i] - m) <= abs(ans - m):
        ans = a[i]

print(a[-1], ans)
