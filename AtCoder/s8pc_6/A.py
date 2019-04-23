n, t = map(int, input().split())
a = list(map(int, input().split()))
print((sum(a) + t - 1) // t)
