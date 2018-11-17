import bisect

n = int(input())
a = sorted(list(map(int, input().split())))

X = a[-1]

i = bisect.bisect(a, X / 2,)
if abs(X / 2 - a[i]) < abs(X / 2 - a[i + 1]):
    print(str(X) + ' ' + str(a[i]))
else:
    print(str(X) + ' ' + str(a[i + 1]))
