s = input()
n = len(s)
if s[-1] == '0' and s[0] == '1' and s[n - 2] == '1' and s[:n - 1] == s[n - 2 :: -1]:
    #s[i] = 「１辺を取り除いてi + 1頂点からなる連結成分を作れる」
    #連結成分のサイズは、1からn//2までチェックすれば十分
    #構成：各iに対し、iの次に1になっているbitを求める
    i = 0
    j = 1
    while j <= n - 2:
        if s[j] == '1':
            for k in range(i, j):
                print(k + 1, j + 1)
            i = j
            j = j + 1
        else:
            j += 1
    print(n - 1, n)

else:
    print(-1)
