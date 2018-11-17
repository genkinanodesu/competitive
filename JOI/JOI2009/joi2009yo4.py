import itertools
n = int(input())
k = int(input())
cards = [input() for i in range(n)]
ans = set()
for choice in itertools.permutations(cards, k):
    seisuu = ''
    for i in range(k):
        seisuu += choice[i]
    ans.add(seisuu)
print(len(ans))
