ticket = input()


for i in range(1 << 3):
    s = ticket[0]
    for j in range(3):
        if (i>>j) & 1:
            s += '+' + ticket[j+1]
        else:
            s += '-' + ticket[j+1]
    if eval(s) == 7:
        print(s+'=7')
        exit()
