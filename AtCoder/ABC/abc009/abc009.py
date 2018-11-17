import itertools
N, K = map(int, input().split())
S = list(input())
letters = sorted(S)

for word in itertools.permutations(letters):
    counter = 0
    for index in range(len(S)):
        if S[index] != word[index]:
            counter += 1
    if counter <= K:
        print(''.join(word))
        exit()
