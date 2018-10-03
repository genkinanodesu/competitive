N = int(input())
z = []
for i in range(N):
    xi, yi = map(int, input().split())
    z.append([xi + yi, xi - yi])

parity = z[0][1] % 2
for i in range(1, N):
    if z[i][0] % 2 != parity:
        print(-1)
        exit()
m = 32
def sign(n):
    pm = []
    diff = (((1 << m) - 1) - n) // 2
    for i in range(m):
        if (diff >> i) & 1 == 1:
            pm.append(-1)
        else:
            pm.append(1)
    return pm

ans = [''] * N
if parity == 0:
    arm = [1] + [1 << k for k in range(m)]
    for i in range(N):
        z[i][0] -= 1
        z[i][1] -= 1
        ans[i] += 'R'
if parity == 1:
    arm = [1 << k for k in range(m)]

for i in range(N):
    ui = sign(z[i][0])
    vi = sign(z[i][1])
    for k in range(m):
        if ui[k] == 1:
            if vi[k] == 1:
                ans[i] += 'R'
            else:
                ans[i] += 'U'
        else:
            if vi[k] == 1:
                ans[i] += 'D'
            else:
                ans[i] += 'L'
print(len(arm))
print(' '.join(map(str, arm)))
for i in range(N):
    print(ans[i])