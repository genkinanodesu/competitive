import numpy as np

N = int(input())
X = list(map(int, input().split()))

A = sorted(X)
m1 = A[ N // 2 - 1]
m2 = A[ N // 2]
for i in range(N):
    if X[i] < m2:
        print(m2)
    else:
        print(m1)
