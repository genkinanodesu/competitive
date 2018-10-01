N = int(input())
A = list(map(int, input().split()))

right = 0
sum_plus = 0
sum_xor = 0
ans = 0
#import pdb; pdb.set_trace()
for left in range(N):
    while right < N and (sum_plus + A[right]) == (sum_xor ^ A[right]):
        sum_plus += A[right]
        sum_xor = sum_xor ^ A[right]
        right += 1
    ans += right - left
    sum_plus -= A[left]
    sum_xor = sum_xor ^ A[left]

print(ans)
