s1 = input()
s2 = input()

#dp[j][i] = (s1のi文字目までとs2のj文字目までの距離)
dp = [[float('inf') for i in range(len(s1)+1)] for j in range(len(s2)+1)]

for i in range(len(s1)+1):
    dp[0][i] = i
for j in range(len(s2)+1):
    dp[j][0] = j

for i in range(len(s1)):
    for j in range(len(s2)):
        if s1[i] == s2[j]:
            dp[j+1][i+1] = dp[j][i]
        else:
            dp[j+1][i+1] = min(dp[j][i], dp[j+1][i], dp[j][i+1]) +1
print(dp[len(s2)][len(s1)])
