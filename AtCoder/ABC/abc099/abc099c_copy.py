import math
def digit_sum(n, d):
    sum = 0
    number = n
    while number > 0:
        sum += number % d
        number = number // d
    return sum
def strangebank(N):
    s = float('inf')
    for i in range(N+1):
        s = min(s, digit_sum(N-i, 6) + digit_sum(i, 9))
    return s

def strangebank2(N):
    ans = []
    for i in range(N+1):
        if i == 0:
            ans.append(0)
        else:
            x = int(math.log(i, 6))
            y = int(math.log(i, 9))
            s = min(ans[i - 6 ** x], ans[i - 9 ** y]) + 1
            ans.append(s)
    return(ans[N])

N = 0
while True:
    if strangebank(N) != strangebank2(N):
        print(N)
        exit()
    N += 1
