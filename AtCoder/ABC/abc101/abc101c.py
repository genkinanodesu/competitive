N, K = map(int, input().split())
A = list(map(int, input().split()))
def kiriage(a, b): #切り上げ
    return (a + b - 1) // b

print(kiriage(N - 1, K - 1))
