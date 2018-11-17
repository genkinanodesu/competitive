n = int(input())
if n == 1:
    print('X')
    exit()

cake = [['.'] * n for _ in range(n)]


for i in range(n):
    for j in range(n):
        if (2 * i - j) % 5 == 0:
            cake[i][j] = 'X'
cake[0][0] = cake[0][n-1] = cake[n-1][0] = cake[n-1][n-1] = 'X'
for i in range(n):
    if i % 3 == 1:
        cake[0][i] = cake[n-1][i] = cake[i][0] = cake[i][n-1] = 'X'

for i in range(n):
    print(''.join(cake[i]))
