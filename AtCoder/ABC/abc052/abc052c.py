
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

N = int(input())
P = sieve(N)
ans = 1
for p in P:
    a = 0
    b = N // p
    while b > 0:
        a += b
        b //= p
    ans = ans * (a + 1) % (10 ** 9 + 7)
print(ans)