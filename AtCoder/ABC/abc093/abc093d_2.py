#泥臭く場合分けすることが大事


import math

def worst(x, y):
    if x > y:
        return worst(y, x)
    elif x == y:
        return 2 * x - 2
    elif y == x + 1:
        return 2 * x - 2
    else:
        z = int(math.sqrt(x * y - 1))
        if z * (z + 1) < x * y:
            return 2 * z - 1
        else:
            return 2 * z - 2
Q = int(input())
rank = [list(map(int, input().split())) for _ in  range(Q)]

for i in range(Q):
    ai, bi = rank[i]
    print(worst(ai, bi))