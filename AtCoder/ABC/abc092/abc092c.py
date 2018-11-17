def cost(M, m):
    if m > 0:
        return 2 * M
    elif M < 0:
        return 2 * (-m)
    else:
        return 2 * (M - m)

N = int(input())
A = [0] + list(map(int, input().split())) + [0]
diff = [A[i + 1] - A[i] for i in range(N + 1)]
ans = sum([abs(diff[i]) for i in range(N + 1)])
for i in range(N):
    if diff[i] * diff[i + 1] < 0:
        print(ans - 2 * min(abs(diff[i]), abs(diff[i + 1])))
    else:
        print(ans)