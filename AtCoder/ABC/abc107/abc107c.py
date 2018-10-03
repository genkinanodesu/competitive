N,  K = map(int, input().split())
candles = list(map(int, input().split()))
ans = float('inf')
for i in range(N - K + 1):
    if candles[i] * candles[i + K - 1] >= 0:
        t = max(abs(candles[i]), abs(candles[i + K - 1]))
    else:
        t = candles[i + K - 1] - candles[i] + min(abs(candles[i]), abs(candles[i + K - 1]))
    ans = min(ans, t)
print(ans)