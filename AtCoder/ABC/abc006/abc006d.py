import bisect
N = int(input())
cards = [int(input()) for i in range(N)]

L = [cards[0]]
for card in cards[1:]:
    if L[-1] < card:
        L.append(card)
    else:
        index = bisect.bisect_left(L, card)
        L[index] = card
print(N - len(L))
