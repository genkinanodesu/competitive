N, M , X, Y = map(int, input().split())
x = list(map(int, input().split()))
y = list(map(int, input().split()))

Z = min(y)
if max(x) < Z and X < Z <= Y:
    print('No War')
else:
    print('War')
