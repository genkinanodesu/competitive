N = int(input())
seq = list(map(int, input().split()))

M, m = max(seq), min(seq)
for i in range(N):
    if seq[i] == M:
        x = i
    if seq[i] == m:
        y = i

print(2 * N - 2)

if M + m >= 0:
    for i in range(N - 1):
        seq[i + 1] += M
        print(x + 1, i + 2)
        if seq[i + 1] > M:
            M = seq[i + 1]
            x = i + 1
        seq[i + 1] += M
        print(x + 1, i + 2)
        if seq[i + 1] > M:
            M = seq[i + 1]
            x = i + 1
else:
    for i in range(N - 1, 0, -1):
        seq[i - 1] += m
        print(y + 1, i)
        if seq[i - 1] < m:
            m = seq[i - 1]
            y = i - 1
        seq[i - 1] += m
        print(y + 1, i)
        if seq[i - 1] < m:
            m = seq[i - 1]
            y = i - 1
#print(seq)