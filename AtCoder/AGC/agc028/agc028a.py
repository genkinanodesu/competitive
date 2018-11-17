import math
def gcd(a, b):
    #aとbの最大公約数を求める
    #math.gcdもしくはnp.gcdを使えばいいのだが、AtCoder上のpythonでは使えない
    if a < b:
        return gcd(b, a)
    if b == 0:
        return a
    else:
        c = a % b
        return gcd(b, c)

def lcm(a, b):
    return (a * b // gcd(a, b))

n, m = map(int, input().split())

s = input()
t = input()

d = gcd(n, m)
l = lcm(n, m)

for i in range(d):
    if s[i * (n // d)] != t[i * (m // d)]:
        print(-1)
        exit()
print(l)