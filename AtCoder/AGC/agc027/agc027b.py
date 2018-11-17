N, X = map(int, input().split())
gar = list(map(int, input().split()))
gar_cum = [0] * (N + 1)
for i in range(N):
    gar_cum[i + 1] = gar_cum[i] + gar[i]

def move_cost(i):
    #i回ゴミを捨てるときの移動コストの最小値
    v = [gar_cum[N - i * j] - gar_cum[max(0, N - i * (j + 1))] for j in range((N + i - 1) // i)]
    return sum([v[j] * max(5, j * 2 + 3) for j in range((N + i - 1) // i)])
def total_cost(i):
    return move_cost(i) + (i + N) * X

ans = float('inf')
for i in range(1, N+1):
    ans = min(ans, total_cost(i))

print(ans)