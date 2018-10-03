a, b = map(int, input().split())

n = b - a
x = int(n * (n + 1) / 2 - b)
print(x)
