N, W = map(int, input().split())
items = [list(map(int, input().split())) for i in range(N)]

dp = [0 for w in range(W+1)]
import pdb; pdb.set_trace()
for item in items:
    for w in range(W, -1, -1):
        limit = item[2]
        key = 1
        while limit > 0:
            if w - item[1] * key >= 0:
                dp[w] = max(dp[w], dp[w - item[1] * key] + item[0] * key)
                limit -= key
                key = min(key*2, limit)
            else:
                break
print(dp)
