def gcd(a, b):
    if(b > a):
        return gcd(b, a)
    if(b == 0):
        return a
    return gcd(b, a % b)

def lcm(a, b):
    return a * b // gcd(a, b)
N = 1000;
l = 1;
for i in range(1000):
    l = lcm(l, i + 1)

for i in range(1000):
    print(l - i - 1)
