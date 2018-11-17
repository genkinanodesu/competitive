N = int(input())
S = input()
ans = [0]
ans[0] = S[1:].count('E')
for i in range(N-1):
    if S[i] == 'E' and S[i+1] == 'E':
        ans.append(ans[i] -1)
    if S[i] == 'E' and S[i+1] == 'W':
        ans.append(ans[i])
    if S[i] == 'W' and S[i+1] == 'E':
        ans.append(ans[i] )
    if S[i] == 'W' and S[i+1] == 'W':
        ans.append(ans[i] +1)
print(min(ans))
    
