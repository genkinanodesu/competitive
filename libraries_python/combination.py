'''
前処理O(N + log mod)でN以下の階乗および階乗の逆数を計算
-> O(1)でcomb(n, k)を計算できる
'''

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
