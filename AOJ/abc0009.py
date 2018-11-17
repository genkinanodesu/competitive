
def pi_x(n):
    '''
    pi_x(n)[i] = pi(i)となるようにする
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
    prime_accum = [0] * (n + 1)
    for i in range(1, n + 1):
        prime_accum[i] = prime_accum[i - 1] + is_prime[i]
    return prime_accum

import sys

P = pi_x(10 ** 6)
a  = []
for line in sys.stdin:
    a.append(int(line))
for num in a:
    print(P[num])