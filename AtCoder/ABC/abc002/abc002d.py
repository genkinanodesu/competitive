N, M = map(int, input().split())
relations = [set(map(int, input().split())) for i in range(M)]

ans = 0
for i in range(2**N):
    subset = set()
    flag = True
    for j in range(N):
        if (i >> j ) & 1 == 1:
            subset.add(j + 1)
    for member1 in subset:
        for member2 in subset:
            if member1 != member2 and not {member1, member2} in relations:
                flag = False
    if flag == True:
        ans = max(ans, len(subset))
print(ans)
