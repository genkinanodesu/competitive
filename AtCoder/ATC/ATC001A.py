H, W = map(int, input().split())
maze = [list(input()) for i in range(H)]
start_x = -1
start_y = -1
goal_x =  -1
goal_y  = -1
# start, goalを探す
for i in range(H):
    for j in range(W):
        if maze[i][j] =='s':
            start_x = i
            start_y = j
        if maze[i][j] =='g':
            goal_x = i
            goal_y = j

# 到達判定リストを作る
Reached = [[False for j in range(W)]for i in range(H)]

def DepthfirstSearch(x,y):
    if (x<0 or W<=x or y<0 or H<=y):
        pass
    elif maze[x][y] == '#':
        pass
    elif Reached[x][y]:
        pass        
    else:
        Reached[x][y] = True
        DepthfirstSearch(x+1, y)
        DepthfirstSearch(x-1, y)
        DepthfirstSearch(x, y+1)
        DepthfirstSearch(x, y-1)
    return Reached

DepthfirstSearch(start_x, start_y)

if Reached[goal_x][goal_y]:
    print('Yes')
else:
    print('No')
