N = int(input())
boxes = [list(map(int, input().split())) for i in range(N)]

boxes.sort(key = lambda x:(x[0], x[1]))

import bisect
tmp0 = [boxes[0][0]]
tmp1 = [boxes[0][1]]

#import pdb;pdb.set_trace()

for box in boxes[1:]:
    if tmp0[-1] < box[0] and tmp1[-1] < box[1]:
        tmp0.append(box[0])
        tmp1.append(box[1])
    elif tmp0[-1] != tmp :
        index = bisect.bisect_left(tmp1, box[1])
        if tmp1[index - 1] > box[1]:
            tmp0[index] = box[0]
            tmp1[index] = box[1]
print(len(tmp1))
