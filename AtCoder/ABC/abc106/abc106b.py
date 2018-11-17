def d(n):
    x = 0
    for i in range(1, n + 1):
        if n % i == 0:
            x += 1
    return x
N = int(input())
ans = 0
for i in range(1, N + 1):
    if i % 2 == 1 and d(i) == 8:
        ans += 1

print(ans)