def sieve(n):
    '''

    :param n:
    :return: n以下の素数のリストを返す
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
    return is_prime

import bisect
Q = int(input())
queries = [list(map(int, input().split())) for _ in range(Q)]
primehantei = sieve(10 ** 5)
like2017 = []
for i in range(10 ** 5):
    if primehantei[i] == True and primehantei[ (i + 1) // 2] == True:
        like2017.append(i)

for i in range(Q):
    li, ri = queries[i]
    print(bisect.bisect_right(like2017, ri) - bisect.bisect_right(like2017, li - 1))