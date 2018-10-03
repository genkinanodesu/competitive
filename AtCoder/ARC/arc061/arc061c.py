s = input()
n = len(s)
ans = 0
for i in range(1 << (n-1)):
    formula = s[0]
    for j in range(n-1):
        if (i >> j) & 1 == 1:
            formula += s[j+1]
        else:
            formula += '+' + s[j+1]
    ans += eval(formula)
print(ans)
                                     
