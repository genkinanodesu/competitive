'''
☆長さnの数列Aの中央値がxであるとは
１．x以上の要素が (n + 1)// 2 個以上
２．そのようなxの中で最小
ということ。
'''

class BIT:
    def __init__(self, n):
        self.bit = [0] * (n+1)

    def sum(self, i):
        '''
        :param i: 
        :return: bit[i]までの和
        '''
        s = 0
        while i > 0:
            s += self.bit[i]
            i -= i & -i
        return s

    def add(self, i, x):
        '''
        :param i:
        :param x:
        :return: bit[i]にxを加える
        '''

        while i < len(self.bit):
            self.bit[i] += x
            i += i & -i

'''
def median(L):
    n = len(L)
    L.sort()
    return L[n // 2]
'''

N = int(input())
a = list(map(int, input().split()))

def ans_bigger(X):
    '''
    答えがX以上かどうかを判定
    つまり、区間[l. r]のうち中央値がX以上であるものが ((N+1) * N /2 + 1 ) //2 個以上かを判定
    '''
    a_X = [1 if a[i] >= X else -1 for i in range(N)]#中央値かどうかの判定には大小関係しかいらない->1, -1に変換
    cum = [N]
    for i in range(N):
        cum.append(cum[i] + a_X[i]) #累積和を取るが、BITを使うため全部0以上に（初項N）
    b = BIT(2 * N + 1)
    ans = 0
    for j in range(N + 1):
        ans += b.sum(cum[j])
        b.add(cum[j], 1)
    if ans >= ((N+1) * N /2 + 1 ) //2:
        return True
    else:
        return False

l = min(a)
r = max(a) + 1
#区間[l, r)を2分探索 「答えがX以上であるもの」のうち最大のものを返す
while r > l + 1:
    if ans_bigger((l + r) // 2):
        l = (l + r) // 2
    else:
        r = (l + r) // 2
print(l)