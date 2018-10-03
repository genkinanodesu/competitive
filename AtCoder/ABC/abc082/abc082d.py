
s = input()
x, y = map(int, input().split())
a = []
b = []

p = 0 #進む長さ
q = 1 #aとbのどちらに加えるか

for i in range(len(s)):
    if s[i] == 'T':
        if q == 1:
            a.append(p)
        else:
            b.append(p)
        q *= -1
        p = 0
    if s[i] == 'F':
        p += 1
        if i == len(s) - 1:
            if q == 1:
                a.append(p)
            else:
                b.append(p)

if a:
    x -= a.pop(0)


def knapsack(L, n):
    #リストLの要素のいくつかの足し合わせでnを作れるか？
    if n < 0 or n > sum(L):
        return False
    else:
        dp = [True] + [False] * (n)
        for l in L:
            for i in range(n, -1, -1):
                if i >= l:
                    dp[i] = dp[i - l] or dp[i]
        return dp[n]

def reachable(L, n):
    #リストLの要素の+-1倍の足し合わせでnを作れるか？
    S = sum(L)
    return (S - n) % 2 == 0 and knapsack(L, (S - n) // 2)


if reachable(a, x) and reachable(b, y):
    print('Yes')
else:
    print('No')

