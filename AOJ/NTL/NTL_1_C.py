n = int(input())
A = list(map(int, input().split()))

def gcd(x,y):
    if max(x, y) % min(x, y) == 0:
        return min(x,y)
    else:
        return gcd ( max(x,y) % min (x,y) , min(x,y))

def lcm(x,y):
    return x * y // gcd(x,y)

ans = A[0]
for i in range(n-1):
    ans = lcm(ans, A[i+1])

print(ans)
