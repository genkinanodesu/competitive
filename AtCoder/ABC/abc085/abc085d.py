N, H = map(int, input().split())
a = []
b = []
for i in range(N):
    ai, bi = map(int, input().split())
    a.append(ai)
    b.append(bi)
    
a_max = max(a)
b.sort(reverse = True)

ans = 0
for i in range(N):
    if b[i] > a_max:
        ans += 1
        H -= b[i]
        if H <= 0:
            print(ans)
            exit()
print(ans + (H + a_max - 1)// a_max)
    
