T = int(input())
tapes = [input() for i in range(T)]

for tape in tapes:
    ans = 0
    while len(tape) >= 5:
        if tape[len(tape) - 5:] == 'tokyo' or tape[len(tape) - 5:] =='kyoto':
           ans += 1
           tape = tape[:len(tape)-5]
        else:
            tape = tape[:len(tape) - 1]
    print(ans)
