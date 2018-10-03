A, B, C, X, Y = map(int, input().split())

ab = min(C * 2, A + B) #A, B1枚ずつ用意するのにかかるお金の最小値
a = min(C * 2, A) #A1枚用意するのにかかる最小値
b = min(C * 2, B) #B1枚
if X >= Y:
    print(ab * Y + a * (X - Y))
else:
    print(ab * X + b * (Y - X))