import bisect
def prime_list(n):
    '''
    n未満の素数のリストを返す
    '''
    num = list(range(2, n))
    prime = []
    while num[0] ** 2 < n:
        p = num.pop(0)
        for j in range(2 * p, n, p):
            if j in num:
                num.remove(j)
        prime.append(p)
    prime += num
    return prime

Q = int(input())
queries = [list(map(int, input().split())) for _ in range(Q)]
primes = prime_list(10 ** 5)
prime_2017like = []
for prime in primes:
    if (prime + 1) // 2 in primes:
        prime_2017like.append(prime)
for i in range(Q):
    li, ri = queries[i]
    print(bisect.bisect_right(prime_2017like, ri) - bisect.bisect_right(prime_2017like, li - 1))
