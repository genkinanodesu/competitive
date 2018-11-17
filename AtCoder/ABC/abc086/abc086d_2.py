import numpy as np

N, K = map(int, input().split())

grid_diff = np.zeros([2 * K, 2 * K])

for _ in range(N):
    xi, yi, ci = input().split()
    if ci == 'C':
        xi = (int(xi) + K) % (2 * K)
        yi = int(yi) % K
    else:
        xi = int(xi) % (2 * K)
        yi = int(yi) % K
    grid_diff[xi, yi] += 1
    grid_diff[(xi + K) % (2 * K), (yi + K) % (2 * K)] += 1
    grid_diff[xi, (yi + K) % (2 * K)] += -1
    grid_diff[(xi + K) % (2 * K), yi] += -1

grid_accum = np.zeros([2 * K + 1, 2 * K + 1])
for i in range(2 * K):
    for j in range(2 * K):
        grid_accum[i + 1, j + 1] = grid_diff[i, j] + grid_accum[i, j + 1] + grid_accum[i + 1, j] - grid_accum[i, j]
print(grid_diff)
print(grid_accum)
print(np.amax(grid_accum))