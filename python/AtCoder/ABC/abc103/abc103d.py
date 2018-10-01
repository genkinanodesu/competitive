N, M = map(int, input().split())
req = [list(map(int, input().split())) for i in range(M)]


'''
#模範解答（想定解）：x[1]でソートし、貪欲にやる
req.sort(key = lambda x:x[1])
last_destroyed = 0
ans = 0
for i in range(M):
    if req[i][0] >= last_destroyed :
        ans += 1
        last_destroyed = req[i][1]
print(ans)
'''
#尺取り法 x[0]でソート　本質的にはどっちも同じこと？
req.sort()
ans = 0
left = 0
right = 0
for i in range(M):
    if req[i][0] >= right:
        ans += 1
        left, right = req[i][0], req[i][1]
    else:
        left = req[i][0]
        right = min(req[i][1], right)

print(ans)
