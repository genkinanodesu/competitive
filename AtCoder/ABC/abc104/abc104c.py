D, G = map(int, input().split())
problem = []
bonus_score = []
for i in range(D):
    pi, ci = map(int, input().split())
    problem.append(pi)
    bonus_score.append(ci)
total_problem = sum(problem)
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
            
