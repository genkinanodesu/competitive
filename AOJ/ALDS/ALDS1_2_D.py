n = int(input())
A = [int(input()) for i in range(n)]
cnt = 0
def insertionSort(A, n, g):
    global cnt
    for i in range(g, n, 1):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt += 1
        A[j + g] = v
    return A

def shellSort(A, n):
    g = 1
    m = 0
    G = []
    while g <= n:
        G.insert(0, g)
        m+= 1
        g = g*3 + 1
    for g in G:
        insertionSort(A, n, g)
    print(m)
    G_str = [str(x) for x in G]
    if G_str:
        print(' '.join(G_str))
    return A
shellSort(A, n)
print(cnt)
for i in range(n):
    print(A[i])