N = int(input())
Seq = list(map(int, input().split()))
def order_2(n): #2でのオーダー
    ans = 0
    while n % 2 == 0:
        ans += 1
        n //= 2
    return ans
print(sum([order_2(a) for a in Seq]))