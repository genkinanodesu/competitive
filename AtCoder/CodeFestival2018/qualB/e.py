n = int(input())
from collections import Counter
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

def ex_euclid(x, y):
    c0, c1 = x, y
    a0, a1 = 1, 0
    b0, b1 = 0, 1
 
    while c1 != 0:
        m = c0 % c1
        q = c0 // c1
 
        c0, c1 = c1, m
        a0, a1 = a1, (a0 - q * a1)
        b0, b1 = b1, (b0 - q * b1)
 
    return [c0, a0, b0] # c0 = a0 * x + b0 * y

def linear(x, y, c):
    # ax + by = cの解を出力
    c0, a0, b0 = ex_euclid(x, y)
    if c % c0 != 0:
        return None
    else:
        b1 = b0 * (c // c0) % x
        b2 = b1 - x
        if abs(b1) < abs(b2):
            b = b1
        else:
            b = b2
        a = (c - b * y) // x
        return a, b

l = [1] * (n + 1)
for i in range(n):
    l[i + 1] = lcm(l[i], i + 1)  #l[i] = (1-i)のLCM

p = [1] * (n + 2)
q = [0] * (n + 2)
# 1/ln = 1/ln-1 * pn + 1/n * qn

for i in range(n, 1, -1):
    if l[i] == l[i - 1]:
        p[i] = p[i + 1]
        q[i] = 0
    else:
        a, b = linear(l[i] // l[i-1], l[i] // i, p[i + 1])
        p[i] = a
        q[i] = b
q[1] = p[2] 
Q = sum([abs(q[i]) for i in range(1, n + 1)])
ans = [[i, q[i]] for i in range(1, n + 1)]
ans.sort(key = lambda x:x[1], reverse = True)
print(Q)
for item in ans:
    if item[1] > 0:
        for i in range(item[1]):
            print('+', item[0])
    elif item[1] < 0:
        for i in range(abs(item[1])):
            print('-', item[0])
