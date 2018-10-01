class BIT:
    '''
    1-based self.bit[0] は無視している
    '''
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
