import sys; sys.setrecursionlimit(1000000000)
N_str = input()
N = int(N_str) + 1
ans = 0
for i in range(len(N_str)):
    quot, res = divmod(N, 10**(i+1))
    ans += quot * (10**i)
    if 10 ** i <= res < 2 * (10**i):
        ans += res - 10 ** i
    if res >= 2 * (10 ** i):
        ans += 10 ** i
print(ans)