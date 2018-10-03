S1 = input()
T = input()

S_list =[]
for i in range(len(S1) - len(T) + 1):
    for j in range(len(T)):
        if S1[i+j] != T[j] and S1[i+j] != '?':
            break
    S = (S1[:i] + T + S1[i + len(T):]).replace('?','a')
    if T in S:
        S_list.append(S)

if len(S_list) > 0:
    print(min(S_list))
else:
    print('UNRESTORABLE')
    
    
    
