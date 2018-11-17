from collections import Counter

n = int(input())
prime_list = []
while n > 1:
    k = 2
    while k ** 2 <= n:
        if n % k == 0:
            prime_list.append(k)
            n //= k
            break
        else:
            k += 1
    else:
        prime_list.append(n)
        n = 1
prime_fact = Counter(prime_list)
ans = 1
for p, k in prime_fact.items():
    ans *= (p ** (k - 1) )*(p - 1)
print(ans)
