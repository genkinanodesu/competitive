import itertools

N = int(input())
S = input()
Q = int(input())
k = list(map(int, input().split()))

p = [(S[i] == 'D') for i in range(N)] + [0] * N
q = [(S[i] == 'M') for i in range(N)] + [0] * N
r = [(S[i] == 'C') for i in range(N)] + [0] * N

P = [0] + list(itertools.accumulate(p))
R = [0] + list(itertools.accumulate(r))

def DMC(k):
    f = [p[i] * R[i + k] for i in range(N)]
    F = [0] + list(itertools.accumulate(f))
    ans = 0
    for y in range(N):
        ans += q[y] * (F[y] - F[max(0, y - k + 2)] - R[y + 1] * (P[y] - P[max(0, y - k + 2)]))
    return ans

for i in range(Q):
    print(DMC(k[i]))