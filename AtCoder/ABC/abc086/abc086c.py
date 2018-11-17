N = int(input())
plan = [[0, 0, 0]] + [list(map(int, input().split())) for _ in range(N)]
diff = [[plan[i + 1][j] - plan[i][j] for j in range(3)] for i in range(N)]

def is_possible(t, x, y):
    if (t + x + y) % 2 == 0 and abs(x) + abs(y) <= t:
        return True
    else:
        return False

for i in range(N):
    ti, xi, yi = diff[i]
    if not is_possible(ti, xi, yi):
        print('No')
        exit()
print('Yes')