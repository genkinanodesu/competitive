import numpy as np
import copy
N, C = map(int, input().split())

x = np.zeros(N)
v = np.zeros(N)
for i in range(N):
    xi, vi = map(int, input().split())
    x[i] = xi
    v[i] = vi

cum_right = np.cumsum(v)
cum_left = np.cumsum(v[::-1])

max_right = np.zeros(N)
max_left = np.zeros(N)
max_right[0] = cum_right[0] - x[0]
max_left[0] = cum_left[0] - (C - x[N - 1])
for i in range(1, N):
    max_right[i] = max(max_right[i - 1], cum_right[i] - x[i])
    max_left[i] = max(max_left[i - 1], cum_left[i] - (C - x[N - 1 - i]))

ans = max(0, max_left[N - 1], max_right[N - 1])

for i in range(N - 1):
    ans = max(ans, cum_left[i] + max_right[N - 2 - i] - (C - x[N - 1 - i]) * 2)
    ans = max(ans, cum_right[i] + max_left[N - 2 - i] - x[i] * 2)
print(int(ans))