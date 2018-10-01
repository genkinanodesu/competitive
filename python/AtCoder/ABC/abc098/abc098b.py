N = int(input())
S = input()
ans = 0
for i in range(1,N):
    S1 = set(S[:i])
    S2 = set(S[i:])
    ans = max(ans, len(S1 & S2))
print(ans)
    
