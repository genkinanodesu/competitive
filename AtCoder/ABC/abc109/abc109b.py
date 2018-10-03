N = int(input())
words = [input() for _ in range(N)]
if len(set(words)) != N:
    print('No')
else:
    for i in range(N - 1):
        if words[i + 1][0] != words[i][-1]:
            print('No')
            exit()
    print('Yes')