import bisect
N = int(input())
weights = [int(input()) for i in range(N)]

piles = []
for weight in weights:
    index = bisect.bisect_left(piles, weight)
    if index > len(piles) - 1:
        piles.append(weight)
    else:
        piles[index] = weight
print(len(piles))
