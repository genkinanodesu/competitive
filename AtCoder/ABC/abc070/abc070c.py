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
    return a * b // gcd(a, b)

def gcd_list(l):
    #リストlに対して、lの要素の最大公約数を返す
    d = l[0]
    for i in range(len(l) - 1):
        d = gcd(d, l[i + 1])
    return d

def lcm_list(l):
    #リストlに対して、lの要素の最大公倍数を返す
    m = l[0]
    for i in range(len(l) - 1):
        m = lcm(m, l[i + 1])
    return m

N = int(input())
T = [int(input()) for i in range(N)]
print(lcm_list(T))
