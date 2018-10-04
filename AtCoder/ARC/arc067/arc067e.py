N, A, B, C, D = map(int, input().split())
dp = [[0] * (N + 1) for _ in range(N + 1)]
#dp[i][j] = i人以下のグループを使って、j人をグループ分けする場合の数
#dp[i][j] = 0 if i < A
#dp[i][0] = 0 if i > 0 , dp[0][0] = 1
#dp[i][j] = sum_{k = 0,C<= k <= D, k * i <= j} dp[i-1][j - k * i] * comb(j, (k * i)) * (k * i)! / (i! **k * k!)

mod = 10 ** 9 + 7
dp_F = [0] * (2000) 
dp_Finv = [0] * (2000)
#dp_F[i] = i!

def factorial(n):
    if dp_F[n] > 0:
        return dp_F[n]
    elif n == 0:
        dp_F[0] = 1
        return 1
    else:
        dp_F[n] = n * factorial(n - 1) % mod
        return dp_F[n]

def inverse(n):
    #modでのnの逆数
    return pow(n, mod - 2, mod)

def factorial_inv(n):
    if dp_Finv[n] > 0:
        return dp_Finv[n]
    elif n == 0:
        dp_Finv[0] = 1
        return 1
    else:
        dp_Finv[n] = inverse(n) * factorial_inv(n - 1) % mod
        return dp_Finv[n]

def combination(n, k):
    return (factorial(n) * inverse(factorial(n - k)) * inverse(factorial(k))) % mod

for i in range(N + 1):
    dp[i][0] = 1

for i in range(A, B + 1):
    for j in range(1, N + 1):
        dp_ij = 0
        dp_ij += dp[i - 1][j]
        k = C
        while k <= j // i and k <= D:
            x = (factorial(j) * factorial_inv(j - k * i) * factorial_inv(k) * pow(factorial_inv(i), k, mod)) % mod
            dp_ij += (dp[i - 1][j - k * i] * x) % mod
            k += 1
        dp[i][j] = dp_ij % mod
print(dp[B][N])