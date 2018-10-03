import numpy as np

N, X = map(int, input().split())
city = [X] + list(map(int, input().split()))
city_diff = np.array([abs(city[i + 1] - city[i]) for i in range(N)])
ans = np.gcd.reduce(city_diff)
print(ans)