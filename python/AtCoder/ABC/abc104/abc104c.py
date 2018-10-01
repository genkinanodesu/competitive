D, G = map(int, input().split())
problem = []
bonus = []
for i in range(D):
    pi, ci = map(int, input().split())
    problem.append(pi)
    bonus.append(ci)
ans = float('inf')
for S in range(1 << D):  # Sは2^Dの元
    score = sum([(problem[j] * 100 * (j + 1) + bonus[j]) * ((S >> j) & 1) for j in range(D)])
    count = sum([problem[j] * ((S >> j) & 1) for j in range(D)])
    if score >= G:
        ans = min(ans,count)
    else:
        for i in range(D):
            if (S >> i) & 1 == 0 and score + problem[i] * 100 * (i + 1) >= G: #Sにiが含まれないとき
                count_2 = count + (G - score + (100 * (i + 1)) - 1) // (100 * (i + 1))
                ans = min(ans, count_2)
print(ans)