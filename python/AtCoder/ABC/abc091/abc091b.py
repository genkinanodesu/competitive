from collections import Counter
N = int(input())
blue = []
for i in range(N):
    blue.append(input())
M = int(input())
red = []
for j in range(M):
    red.append(input())
blue_Counter = Counter(blue)
red_Counter = Counter(red)
ans = blue_Counter - red_Counter
if not ans.most_common():
    print(0)
else:
    print(ans.most_common()[0][1])
