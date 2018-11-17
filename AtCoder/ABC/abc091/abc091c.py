N = int(input())
red_points  = sorted([list(map(int, input().split())) for i in range(N)], key = lambda x: (-x[1], -x[0]))
blue_points = sorted([list(map(int, input().split())) for i in range(N)], key = lambda x: (x[0], x[1]))
for blue_point in blue_points:
    blue_point.append(False)

ans = 0
for red_point in red_points:
    for blue_point in blue_points:
        if red_point[0] < blue_point[0] and red_point[1] < blue_point[1] and not blue_point[2]:
            ans += 1
            blue_point[2] = True
            break
print(ans)
