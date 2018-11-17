N, K = map(int, input().split())
ball = list(map(int, input().split()))

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
def gcd_list(l):
    #リストlに対して、lの要素の最大公約数を返す
    d = l[0]
    for i in range(len(l) - 1):
        d = gcd(d, l[i + 1])
    return d

d = gcd_list(ball)
if K <= max(ball) and K % d == 0:
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')