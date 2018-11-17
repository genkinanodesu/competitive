N = int(input())
a = list(map(int, input().split()))

right = 0
ans = 0
for left in range(N):
    while right < N-1 and a[right] < a[right+1]:
        right += 1
    res = right - left
    ans += res + 1
    if right == left:
        right += 1

print(ans)
