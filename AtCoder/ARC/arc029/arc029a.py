N = int(input())
t = [int(input()) for i in range(N)]
ans = float('inf')
for i in range(1 << N):
    t1 = 0
    t2 = 0
    for j in range(N):
        if (i>>j) & 1:
            t1 += t[j]
        else:
            t2 += t[j]
    ans = min(max(t1,t2), ans)
print(ans)
