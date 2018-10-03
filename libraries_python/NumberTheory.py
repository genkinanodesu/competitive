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

def divisor(n):
    #nの約数のリストを返す
    m = int(math.sqrt(n))
    ans = []
    for i in range(1, m + 1):
        if n % i == 0:
            if i < n //i:
                ans += [i, n // i]
            else:
                ans += [i]
    ans.sort()
    return ans

def sieve(n):
    '''
    :param n:
    :return: n以下の素数のリストを返す
    エラトステネスの篩→O(n log log n)
    '''
    prime = []
    is_prime = [True] * (n + 1) #is_prime[i] = Trueならiは素数
    is_prime[0] = False
    is_prime[1] = False
    for i in range(2, n+1):
        if is_prime[i]:
            prime.append(i)
            for j in range(2 * i, n + 1, i):
                is_prime[j] = False
    return prime

def is_prime(n):
    # nが素数かどうか判定
    #O(sqrt(n)) で判定
    if n <= 1:
        return False
    else:
        m = 2
        while m * m <= n:
            if n % m == 0:
                return False
            m += 1
        return True
