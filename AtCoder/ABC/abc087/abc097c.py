import numpy as np
N = int(input())
upper = np.array(list(map(int, input().split())))
lower = np.array(list(map(int, input().split())))

upper_cum = np.cumsum(upper)
lower_cum = np.cumsum(lower[::-1])

print(max(upper_cum + lower_cum[::-1]))
