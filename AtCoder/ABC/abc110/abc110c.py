S = input()
T = input()
n = len(S)

X = [[] for _ in range(26)]
Y = [[] for _ in range(26)]
for i in range(n):
    s = ord(S[i]) - 97
    t = ord(T[i]) - 97
    X[s].append(i)
    Y[t].append(i)

P = [tuple(x) for x in X]
Q = [tuple(y) for y in Y]
if set(P) == set(Q):
    print('Yes')
else:
    print('No')
