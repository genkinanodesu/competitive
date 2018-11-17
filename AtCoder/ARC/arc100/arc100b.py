import bisect
N = int(input())
A = list(map(int, input().split()))
accum = [0 for i in range(N + 1)]
for i in range(N):
    accum[i + 1] = accum[i] + A[i]
total = accum[N]
#accum[i + 1] = A[0] + A[1] + ... + A[i]
#sum(A[i:j]) = A[i] + A[i+1] + ... + A[j-1] = accum[j] - accum[i]
ans = float('inf')
for i in range(2, N - 1, 1): #2番目の区切りを A[i-1]とA[i]の間に入れる
    zenhan = accum[i] #(= sum(A[:i]))
    kouhan = total - zenhan #(= accum[N] - accum[i] = sum(A[i:N]))
    index1l = bisect.bisect(accum, zenhan // 2, lo = 2, hi = i) - 1
    index1r = min(index1l + 1, i - 1)
    index3l = bisect.bisect(accum, zenhan + (kouhan // 2), lo = i + 2, hi = N) - 1
    index3r = min(index3l + 1, N - 1)
    for index1 in (index1l, index1r):
        for index3 in (index3l, index3r):
            B, C, D, E = accum[index1], zenhan - accum[index1], accum[index3] - zenhan, total - accum[index3]
            M = max(B, C, D, E)
            m = min(B, C, D, E)
            ans = min(ans, M - m)
print(ans)