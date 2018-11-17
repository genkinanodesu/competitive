N, K = map(int, input().split())
S = [int(input()) for i in range(N)]

ans = 0
if 0 in S:
    ans = N
else:
    right = 0
    prod = 1
    for left in range(N):
        while right < N and prod * S[right] <= K:
            prod *= S[right]
            right += 1
        ans = max(ans, right-left)
        if right == left:
             right += 1
             prod = 1
        else:
            prod //= S[left]

print(ans)
