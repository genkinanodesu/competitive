import sys; sys.setrecursionlimit(1000000000)

D = int(input())
N = input()
mod = 1000000007
dp_memo = [[[-1 for s in range(D) ]for _ in range(2)] for k in range(len(N)+1) ]
def rec(k = 0, tight = True, sum = 0):
    if k == len(N):
        return 1 if sum == 0 else 0
    elif dp_memo[k][tight][sum] >= 0:
        return dp_memo[k][tight][sum]
    else:
        r = int(N[k]) if tight else 9
        res = 0
        for i in range(r+1):
            res = (res +  (rec(k + 1, tight & (i == r), (sum + i) % D))) % mod
        dp_memo[k][tight][sum] = res
        return res
print((rec() - 1 + mod)% mod) # 000....0を除外

