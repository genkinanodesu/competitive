N, M ,A, B = map(int, input().split())
X = [B] * N
for _ in range(M):
    Li, Ri = map(int, input().split())
    for j in range(Li - 1, Ri):
        X[j] = A

print(sum(X))

