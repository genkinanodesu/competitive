N, K= map(int, input().split())
mod = 10 ** 9 + 7

a = [0] * (N + 1) #a[i] = i番目を終点としたときの場合の数
s = [0] * (N + 1) #s[i] = a[0] + a[1] + ... + a[i]
t = [0] * (N + 1) #t[i] = s[0] + s[1] + ... + s[i]

for i in range(1, K):
    a[i] = pow(2, max(0, i - 2), mod)
    s[i] = (s[i - 1] + a[i]) % mod
    t[i] = (t[i - 1] + s[i]) % mod

for i in range(K, N + 1):
    a[i] = (t[i - 2] - t[max(0, i - K - 1)]) % mod
    s[i] = (s[i - 1] + a[i]) % mod
    t[i] = (t[i - 1] + s[i]) % mod
print(a[N])
