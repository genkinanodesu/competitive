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
    return prime

