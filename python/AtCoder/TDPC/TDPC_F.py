import copy
S = input()
K = int(input())
N = len(S)
'''
dp[i] = (S[i] を1文字目として使ったときに何通りの部分文字列がありうるか)
dp[len(S)] = 0とする
next_pos[i + 1][x] = (S[i]よりあとにはじめてxが登場するindex、登場しない場合はlen(S)とするとよい）

→dp[i] = sum(dp[next_pos[i + 1][x] for x in アルファベット) + 1
'''

dp = [0] * (N + 1)
next_pos = [[N] * 26 for _ in range(N + 1)]

for i in range(N - 1, -1, -1):
    x = ord(S[i]) - 97
    next_pos[i] = copy.deepcopy(next_pos[i + 1])
    next_pos[i][x] = i

for i in range(N - 1, -1, -1):
    dp[i] = sum([dp[next_pos[i + 1][x]] for x in range(26)]) + 1


if K > sum([dp[next_pos[0][x]] for x in range(26)]):
    print('Eel')
else:
    ans = ''
    i = 0
    while i < len(S):
        x = 0
        while K > dp[next_pos[i][x]]:
            K -= dp[next_pos[i][x]]
            x += 1
        ans += chr(x + 97)
        i = next_pos[i][x]
        K -= 1
