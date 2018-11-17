import sys; sys.setrecursionlimit(1000000000)

A, B = input().split()
A_zero = A.zfill(len(B))

dp_memo = [[[[-1 for taboo in range(2)] for sup_tight in range(2)] for inf_tight in range(2)] for k in range(len(B)+1)]

def rec(k = 0, inf_tight = True, sup_tight = True, taboo = False):
    if dp_memo[k][inf_tight][sup_tight][taboo] >= 0:
        return dp_memo[k][inf_tight][sup_tight][taboo]
    elif k == len(B):
        dp_memo[k][inf_tight][sup_tight][taboo] = 1 if taboo else 0
        return 1 if taboo else 0
    else:
        lower_bound = int(A_zero[k]) if inf_tight else 0
        upper_bound = int(B[k]) if sup_tight else 9
        res = 0
        for i in range(lower_bound, upper_bound + 1, 1):
            if taboo:
                res += rec(k+1, inf_tight & (i == lower_bound), sup_tight & (i == upper_bound), True)
            else:
                res += rec(k+1, inf_tight & (i == lower_bound), sup_tight & (i == upper_bound), i == 4 or i == 9)
        dp_memo[k][inf_tight][sup_tight][taboo] = res
        return res
print(rec())