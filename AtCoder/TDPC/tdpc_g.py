S = input()
K = int(input())
N = len(S)
import copy
#next_pos[i + 1][x] = S[i]より後（s[i + 1:]）で初めて文字xが現れるindex 現れない場合はN
next_pos = [[N] * 26 for _ in range(N + 1)]

for i in range(N - 1, -1, -1):
    next_pos[i] = copy.deepcopy(next_pos[i + 1])
    x = ord(S[i]) - 97
    next_pos[i][x] = i

dp = [0] * (N + 1)
#dp[i] = S[i]を1文字目とした部分文字列の数

for i in range(N - 1, -1, -1):
    dp[i] = 1 + sum([dp[next_pos[i + 1][x]] for x in range(26)])

def Kth_substr(k):
    if sum([dp[next_pos[0][x]] for x in range(26)]) < k:
        return 'Eel'
    else:
        i = 0
        ans = ''
        while k > 0:
            c = 0
            wa = 0
            while wa + dp[next_pos[i][c]] < k:
                wa += dp[next_pos[i][c]]
                c += 1
            ans += chr(c + 97)
            k -= (1 + wa)
            i = next_pos[i][c] + 1
        return ans
print(Kth_substr(K))