N = int(input())
A = list(map(int, input().split()))

right = 0
snacks = set()
ans = 1
for left in range(N):
    while right < N and not(A[right] in snacks):
        snacks.add(A[right])
        right += 1
    ans = max(right-left, ans)
    snacks.remove(A[left])

print(ans)
