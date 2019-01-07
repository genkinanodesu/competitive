import numpy as np

N = int(input())
a = list(map(int, input().split()))
b = np.array([abs(N * a[i] - sum(a)) for i in range(N)])
print(b.argmin())