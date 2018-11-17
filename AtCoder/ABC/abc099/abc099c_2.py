N = int(input())

def f_6(x):
    ans = 0
    while x > 0:
        ans += x % 6
        x = x // 6
    return ans

def f_9(x):
    ans = 0
    while x > 0:
        ans += x % 9
        x = x // 9
    return ans



import math
N = int(input())
ans = []
for i in range(N+1):
    if i == 0:
        ans.append(0)
    else:
        x = int(math.log(i, 6))
        y = int(math.log(i, 9))
        s = min(ans[i - 6 ** x], ans[i - 9 ** y]) + 1
        ans.append(s)
print(ans[N])
