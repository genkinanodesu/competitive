def smallest_factor(integer):
    j = 2
    while j :
        if j ** 2 > integer:
            return integer
        elif integer % j == 0:
            return j
        else:
            j += 1

n = int(input())
start = str(n)
prime_factors = []
while n >= 2:
    prime_factors.append(str(smallest_factor(n)))
    n //= smallest_factor(n)

print(start +  ': '+ ' '.join(prime_factors))