H, W = map(int, input().split())
grid = [list(input()) for i in range(H)]
diff = [(1,0), (-1, 0), (0, 1), (0, -1)]

for i in range(H):
    for j in range(W):
        if grid[i][j] == '#':
            flag = False
            for d in diff:
                if 0 <= i + d[0] < H and 0 <= j + d[1] < W:
                    if grid[i+d[0]][j+d[1]] =='#':
                        flag = True
            if not flag:
                print('No')
                exit()
print('Yes')
                    
                    
