N = int(input())
A = list(map(int, input().split()))
str_A = [str(a) for a in A]
result = ' '.join(str_A)
print(result)
for i in range(1, N, 1):
    v = A[i]
    j = i - 1
    while j >= 0 and A[j] > v:
        A[j + 1] = A[j]
        j -= 1
    A[j+1] = v
    str_A = [str(a) for a in A]
    result = ' '.join(str_A)
    print(result)