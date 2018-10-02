D, G = map(int, input().split())
p = []
c = []
for i in range(D):
    pi, ci = map(int, input().split())
    p.append(pi)
    c.append(ci)
ans = float('inf')
#(i, j) : i→完全に解く問題の集合
for i in range(1 << D):
    score = 0
    problems = 0
    for j in range(D): #iに対応する問題の集合を完全に解く
        if (i >> j) & 1 == 1:
            score += (j + 1) * 100 * p[j] + c[j]
            problems += p[j]
    if score >= G:
        ans = min(ans, problems)
    else:
        k = D




dp= [[0 for k in range(total_problem + 1)] for i in range(D+1)]

for i in range(D):
    for k in range(total_problem + 1):
        for j in range(min(problem[i], k) + 1):
            dp[i+1][k] = max(dp[i+1][k], dp[i][k - j] + (i + 1) * 100 * j + (j//problem[i]) * bonus_score[i])
ans = 0
#import pdb; pdb.set_trace()
while dp[D][ans] < G:
    ans += 1
print(ans)
            
