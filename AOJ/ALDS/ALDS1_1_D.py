n = int(input())
prices = [int(input()) for _ in range(n)]
max_profit = prices[1] - prices[0]
min_price = prices[0]
for price in prices[1:]:
    max_profit = max(max_profit, price - min_price)
    min_price = min(min_price, price)

print(max_profit)