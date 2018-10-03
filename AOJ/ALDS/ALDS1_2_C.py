import copy
def BubbleSort(A):
    C = copy.deepcopy(A)
    N = len(A)
    for i in range(N):
        for j in range(N-1, i, -1):
            if int(C[j][1]) < int(C[j -1][1]):
                C[j], C[j - 1] = C[j - 1], C[j]
    return C

def SelectionSort(A):
    C = copy.deepcopy(A)
    N = len(A)
    for i in range(N):
        min_temp = i
        for j in range(i, N, 1):
            if int(C[j][1]) < int(C[min_temp][1]):
                min_temp = j
        C[min_temp], C[i] = C[i], C[min_temp]
    return C

def isStable(A, B):
    N = len(A)
    M = len(B)
    for i in range(N):
        for j in range(i+1, N, 1):
            for x in range(M):
                for y in range(x+1, M, 1):
                    if A[i][1] == A[j][1] and A[i] == B[y] and A[j] == B[x]:
                        return 'Not stable'
    else:
        return 'Stable'

N = int(input())
cards = input().split()
result1 = ' '.join(BubbleSort(cards))
result2 = ' '.join(SelectionSort(cards))
print(result1)
print(isStable(cards, BubbleSort(cards)))
print(result2)
print(isStable(cards, SelectionSort(cards)))