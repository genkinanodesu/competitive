T = input()
N = len(T)
mod = 10**9 + 7

def func(X, Y):
    if Y == 0:
        return X
    else:
        return ((3* X + Y) * pow(3, Y - 1, mod)) % mod

A_left = 0
q_left = 0
q_right = T[1:].count('?')
C_right = T[1:].count('C')
ans = 0
for i in range(1, N-1, 1):
    if T[i-1] == 'A':
        A_left += 1
    if T[i-1] =='?':
        q_left += 1
    if T[i] == '?':
        q_right -= 1
    if T[i] == 'C':
        C_right -= 1
    if T[i] == 'B' or T[i] == '?':
        ans += func(A_left, q_left) * func(C_right, q_right)
        ans %= mod
print(ans)
