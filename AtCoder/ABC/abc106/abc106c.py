S = input()
K = int(input())
day = 5 * pow(10, 15)


for i in range(K):
    if S[i] != '1':
        print(S[i])
        exit()
print('1')
