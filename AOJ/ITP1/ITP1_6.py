n = int(input())
cards = []
for _ in range(n):
    suit, num = input().split()
    num = int(num)
    cards.append((suit, num))

for suit in ('S', 'H', 'C', 'D'):
    for num in range(13):
        if not((suit, num + 1) in cards):
            print(suit, num + 1)
