import heapq

N = int(input())
seq = list(map(int, input().split()))

zenhan = seq[:N]
kouhan = list(map(lambda x: -x, seq[2*N:])) #後半は-1倍しておく
heapq.heapify(zenhan)
heapq.heapify(kouhan)

zenhan_sum_max = [0 for i in range(N + 1)] #zenhan_sum_max[i] = a0, ..., a_(N+i-1)からN個取るときの最大値
kouhan_sum_min = [0 for i in range(N + 1)] #kouhan_sum_min[i] = a_(N+i), ..., a_(3N-1)からN個取るときの最小値

zenhan_sum_max[0] = sum(seq[:N])
kouhan_sum_min[N] = sum(list(map(lambda x: -x, seq[2*N:])))
for i in range(N):
    new = seq[N + i]
    pop = heapq.heappushpop(zenhan, new)
    zenhan_sum_max[i + 1] = zenhan_sum_max[i] + new - pop

for i in range(N - 1, -1, -1):
    new = -seq[N + i]
    pop = heapq.heappushpop(kouhan, new)
    kouhan_sum_min[i] = kouhan_sum_min[i + 1] + new - pop

print(max([zenhan_sum_max[i] + kouhan_sum_min[i] for i in range(N + 1)]))
