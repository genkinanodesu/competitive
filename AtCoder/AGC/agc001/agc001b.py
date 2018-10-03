N, X = map(int, input().split())
path = N
a, b = X, N - X
if a < b:
    a, b = b, a
while b > 0:
    path += b * (a // b) * 2
    a, b = b, a % b
path -= a
print(path)