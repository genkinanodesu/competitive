N = int(input())
M = N // 2
X = list(map(int, input().split()))
A = sorted([X[i] - (i + 1) for i in range(N)])
if N == 1:
    print(0)
else:
    print(sum(A[-M:]) - sum(A[:M]))
