N = int(input())

def digit_sum(n, d):
    sum = 0
    number = n
    while number > 0:
        sum += number % d
        number = number // d
    return sum

ans = float('inf')
for i in range(N+1):
    ans = min(ans, digit_sum(N-i, 6) + digit_sum(i, 9))
print(ans)
