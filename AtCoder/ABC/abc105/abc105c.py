N = int(input())
S = []
if N == 0:
    print('0')
    exit()
while N != 1:
    if N % (-2) == -1:
        S.append(1)
        N = (N - 1) // -2
    else:
        S.append(0)
        N = N // -2
S.append(1)
ans = ''
for s in S[::-1]:
    ans += str(s)
print(ans)