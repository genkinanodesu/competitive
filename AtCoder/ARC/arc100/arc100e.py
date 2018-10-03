import numpy as np

N = int(input())
A = np.array(map(int, input().split()))

#dp[S] = A[S], -inf で初期化　Sの部分集合TのうちA[T]が(最大のもの, 次に大きいもの)　を入れていく
dp = np.array([[A[S], -float('inf')] for S in range(1 << N)])
#dp = [[A[S], -float('inf') ] for S in range(1 << N)]
for i in range(N):
    for T in range( 1 << N):
        if (T >> i) & 1 == 1: # Tがiを含むとき
            merge =np.hstack(dp[T], dp[T ^ (1 << i)])
            dp[T] = np.sort(merge)[:2:-1]
ans = -float('inf')
for S in range(1, 1 << N , 1):
    ans = max(ans, sum(dp[S]))
    print(ans)