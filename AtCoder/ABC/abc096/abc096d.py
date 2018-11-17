def prime_list(n):
    '''
    n以下の素数のリストを返す
    '''
    A = list(range(2, n + 1, 1))
    prime = []
    p_max = A.pop(0)    
    while A[-1] >= p_max ** 2:
        for n in A:
            if n % p_max == 0:
                A.remove(n)
        prime.append(p_max)
        p_max = A.pop(0)
    prime.append(p_max)
    prime += A
    return prime

N = int(input())
ans = ['2']
for prime in prime_list(1362):
    if len(ans) < N:
        if prime % 5 == 1:
            ans.append(str(prime))

print(' '.join(ans))
