X = sorted(list(map(int, input().split())))

if X[0] % 2 == X[1] % 2 == X[2] % 2:
    print((X[2] - X[0]) // 2 + (X[2] - X[1]) // 2)
elif X[0] % 2 == X[1] % 2:
    print((X[2] - X[0]) // 2 + (X[2] - X[1]) // 2 + 1)
else:
    print((X[2] - X[0]) // 2 + (X[2] - X[1]) // 2 + 2)
