N = int(input())
A = list(map(int, input().split()))
flag = 1
swap_counter = 0

while flag:
    flag = 0
    for j in range(N-1, 0, -1):
        if A[j - 1] > A[j]:
            A[j - 1], A[j] = A[j], A[j - 1]
            swap_counter += 1
            flag = 1
A_str = [str(a) for a in A]
result = ' '.join(A_str)
print(result)
print(swap_counter)