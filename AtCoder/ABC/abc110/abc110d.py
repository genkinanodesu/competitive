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

dp_memo = [0] * 50
def f(x):
    #f(x) = (x + N -1) C (N - 1)
    if dp_memo[x] > 0:
        return dp_memo[x]
    elif x == 0:
        return 1
    else:
        return (f(x - 1) * (x + N - 1)) // x

N, M = map(int, input().split())
P = sieve(4 * 10 ** 4)
index = []
i = 0
while M > 1 and i < len(P):
    cnt = 0
    while M % P[i] == 0:
        cnt += 1
        M //= P[i]
    i += 1
    if cnt > 0:
        index.append(cnt)

if M > 1:
    index.append(1)

ans = 1
for i in index:
    ans = ans * f(i) % (10 ** 9 + 7)

print(ans)