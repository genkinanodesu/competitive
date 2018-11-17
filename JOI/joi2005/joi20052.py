def gcd(a, b):
    if a < b:
        return gcd(b, a)
    if b == 0:
        return a
    else:
        c = a % b
        return gcd(b, c)

def gcd_list(l):
    d = l[0]
    for i in range(len(l) - 1):
        d = gcd(d, l[i + 1])
    return d

def divisor(n):
    #nの約数のリストを返す
    import math
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

n = int(input())
d = gcd_list(list(map(int, input().split())))

common_divs = divisor(d)
for i in common_divs:
    print(i)