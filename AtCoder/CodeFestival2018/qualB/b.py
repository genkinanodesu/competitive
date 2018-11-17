n, x = map(int, input().split())
a = []
b = []
for _ in range(n):
    ai, bi = map(int, input().split())
    a.append(ai)
    b.append(bi)
s = sum([a[i] * b[i] for i in range(n)])
s += max(b) * x
print(s)