import sys; sys.setrecursionlimit(1000000)

n = int(input())
a = list(map(int, input().split()))
t = [0] * (n + 1)
#t[i] = a0 + ... + a(i-1)
for i in range(n):
    t[i + 1] = t[i] + a[i]

'''
前処理O(N + log mod)でN以下の階乗および階乗の逆数を計算
-> O(1)でcomb(n, k)を計算できる
'''

mod = 10 ** 9 + 7
dp_F = [0] * (n * 2) 
dp_Finv = [0] * (n * 2)
dp_inv = [0] * (n * 2)
#dp_F[i] = i!

def factorial(n):
    if dp_F[n] > 0:
        return dp_F[n]
    elif n == 0:
        dp_F[0] = 1
        return 1
    else:
        dp_F[n] = n * factorial(n - 1) % mod
        return dp_F[n]

def inverse(n):
    #modでのnの逆数
    return pow(n, mod - 2, mod)

c = factorial(n)
def f(k):
    return ((c * inverse(k)) % mod)

ans = 0
for i in range(1, n):
    ans += t[i] * (f(n - i + 1) - f(i + 1))
    ans %= mod
ans += t[n] * sum([f(i) for i in range(1, n + 1)])
ans %= mod
print(ans)