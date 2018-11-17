import numpy as np
N, C = map(int, input().split())
x = np.zeros(N)
v = np.zeros(N)
for i in range(N):
    xi, vi = map(int, input().split())
    x[i] = xi
    v[i] = vi

v_cum = np.cumsum(v)

v_cum - x
