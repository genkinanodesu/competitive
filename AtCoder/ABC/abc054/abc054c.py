import itertools

N, M = map(int, input().split())
nodes = [set(map(lambda x: int(x)-1, input().split())) for i in range(M)]
ans = 0
for path in itertools.permutations(range(N)):
    flag = True
    for i in range(N-1):
        if not ({path[i], path[i+1]} in nodes and path[0] == 0):
            flag = False
    if flag:
        ans += 1
print(ans)
                        
    
