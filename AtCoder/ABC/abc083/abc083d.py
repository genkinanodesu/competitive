import numpy as np
S = np.array([int(i) for i in input()])
N = len(S)
T = np.abs(np.diff(S))
K = N
for i in range(N // 2):
    if T[i] == 1 or T[N - 2 - i] == 1:
        K = N - i - 1

print(K)