import itertools

N, M = map(int, input().split())
cakes = [list(map(int, input().split())) for _ in range(N)]
signs = [1, -1]
ans = 0
for axis in itertools.product(signs, repeat = 3):
    cakes_proj = [sum([cake[i] * axis[i] for i in range(3)]) for cake in cakes]
    cakes_proj.sort(reverse = True)
    ans = max(ans, sum(cakes_proj[:M]))
print(ans)