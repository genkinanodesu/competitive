import numpy as np
H, W = map(int, input().split())
grid = np.array([list(input()) for _ in range(H)])
grid_1 = grid[~np.all(grid == '.', axis = 1), :]
grid_2 = grid_1[:, ~np.all(grid == '.', axis = 0)]
for i in range(grid_2.shape[0]):
    print(''.join(grid_2[i]))