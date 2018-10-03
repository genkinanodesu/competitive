N = int(input())
A = list(map(int, input().split()))
swap_counter = 0
for i in range(N):
    min_temp = i
    for j in range(i, N, 1):
        if A[j] < A[min_temp]:
            min_temp = j
    if i < min_temp:
        A[i], A[min_temp] = A[min_temp], A[i]
        swap_counter += 1
A_str = [str(a) for a in A]
result = ' '.join(A_str)
print(result)
print(swap_counter)