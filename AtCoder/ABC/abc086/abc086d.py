N, K = map(int, input().split())
req = []
for _ in range(N):
    xi, yi, ci = input().split()
    xi = int(xi) % (2 * K)
    yi = int(yi) % (2 * K)
    ci = 1 if ci == 'B' else 0
    req.append([xi, yi, ci])
def checker(i, j, x, y):
    '''
    区切りをx = i y = jで入れたときの市松模様
    '''
    x = x % (2 * K)
    y = y % (2 * K)
    return ((x < i) + (x < (i + K)) + (y < j) + (y <(j + K))) % 2
ans = 0
for i in range(K):
    for j in range(K):
        count = 0
        for q in req:
            if checker(
    
