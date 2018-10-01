import bisect

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
digit = 28 #ai + bi < 2 ** 29 なので、28桁目まで考えればいい
ans = 0
for k in range(digit):
    #ai+bi の下(k + 1)桁について考える
    A_res = [A[i] % (1 << (k + 1)) for i in range(N)]
    B_res = [B[i] % (1 << (k + 1))  for i in range(N)]
    B_res.sort()
    num = 0
    for a in A_res:
        T1 = bisect.bisect_left(B_res, (1 << k) * 2 - a ) - bisect.bisect_left(B_res, (1 << k) - a)
        T2 = bisect.bisect_left(B_res, (1 << k) * 4 - a ) - bisect.bisect_left(B_res, (1 << k) * 3 - a )
        num  = (num + T1 + T2) % 2
        #ai + bi が[2**k, 2**k * 2)もしくは[2**k * 3, 2**k * 4)の間にあるときのみ考えれば良い
    ans += num * (1 << k)
print(ans)