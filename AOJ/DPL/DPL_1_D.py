import bisect
n = int(input())
seq = [int(input()) for i in range(n)]

LIS = []
for number in seq:
    index = bisect.bisect_left(LIS, number)
    if index >= len(LIS):
       LIS.append(number)
    else:
        LIS[index] = number
print(len(LIS))
