X = int(input())

powers = {1}

for p in range(2, 32):
    pw = p*p
    while pw <= X:
        powers.add(pw)
        pw *= p

print(max(powers))
