p = int(input())
n = int(input()) % (p - 1)

def gcd(a, b):
    if a < b:
        return gcd(b, c)
    elif b == 0:
        return a
    else:
        c = a % b
        return gcd(b, c)

'''
x^n + y^n = z^nの解は、
1. x != 0のとき
    1 + Y^n = Z^n の解(Y, Z)の個数 * (p -1)
2. x = 0のとき
    Y^n = Z^nの解の個数
    これはY != 0のとき、Y^nの取りうる値は
    d = (p - 1, n)として (p - 1) / d通り、各値につきd^2個の解があるので
    d^2 * (p - 1) / d = d * (p - 1)個
    Y = 0のとき (0, 0)のみ
よって1 + d * (p - 1) + (p - 1) * (1 + y^n = z^nの解の個数)　をかうんとすればよい。

'''
powers = [0] * p
for i in range(p):
    powers[pow(i, n, p)] += 1

x = 0
for i in range(p):
    x += powers[i] * powers[(i + 1) % p]

d = gcd(p - 1, n)

ans = (p - 1) * x + d * (p -1) + 1
print(ans)
