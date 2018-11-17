N, W = map(int, input().split())
values = []
weights = []
for _ in range(N):
    vi, wi = map(int, input().split())
    values.append(vi)
    weights.append(wi)
def fullsearch(S):
    k = len(S)
    ans = set()
    for i in range(1<<k):
        wa = 0
        for j in range(k):
            if 1 & (i >> j) :
                wa += S[j]
        ans.add(wa)
    return(sorted(list(ans)))

import pdb; pdb.set_trace()
