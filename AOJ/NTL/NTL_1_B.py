m, n = map(int, input().split())
n %= 1000000006
ans = 1
while n > 0:
    ans = (ans * m) % 1000000007
    n -= 1
print(ans)