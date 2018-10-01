N, W = map(int, input().split())

#items = [list(map(int, input().split())) for i in range(N)]
values = []
weights = []
for i in range(N):
    vi, wi, mi = map(int, input().split())
    key = 1
    while mi > 0:
        values.append(vi * key)
        weights.append(wi * key)
        mi -= key
        key = min(key * 2, mi)
'''
for item in items:
    key = 1
    while item[2] > 0:
        values.append(item[0] * key)
        weights.append(item[1] * key)
        item[2] -= key
        key = min(key * 2, item[2])
'''
#あとはvalues, weightsに対してknapsack DPするだけ
num = len(values)
dp = [0 for w in range(W+1)]
for i in range(num):
    wi = weights[i]
    vi = values[i]
    for w in range(W, wi -1 , -1):
        if dp[w] < dp[w - wi] + vi:
            dp[w] = dp[w - wi] + vi

print(dp[W])
'''
values = []
weights = []
limits = []
for i in range(N):
    item = list(map(int, input().split()))
    values.append(item[0])
    weights.append(item[1])
    limits.append(item[2])
#import pdb; pdb.set_trace()
dp = [0 for w in range(W+1)]
for i in range(N):
    key = 1
    res = limits[i] - key
    while key > 0:
        for w in range(W, 0, -1):
            if w - weights[i] * key >= 0:
                dp[w] = max(dp[w], dp[w - weights[i] * key] + values[i]* key)
        key = min(key * 2, res)
        res -= key
print(dp[W])
'''
