T = int(input())
N = int(input())
takos = list(map(int, input().split()))
M = int(input())
guests = list(map(int, input().split()))

got_takoyaki = [False for i in range(M)]
index = 0
for tako in takos:
    if index <= M - 1 and got_takoyaki[index] == False and tako <= guests[index] <= tako + T:
        got_takoyaki[index] = True
        index += 1
if got_takoyaki[M-1] == True:
    print('yes')
else:
    print('no')
        
