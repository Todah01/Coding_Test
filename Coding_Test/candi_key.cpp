#if 0
from itertools import combinations
from collections import Counter

def solution(relation) :
    answer = 0
    data_list = [[]for i in range(len(relation[0]))]

    for idx in range(len(relation[0])) :
        for info in relation :
data_list[idx].append(info[idx])

exclude_list = []
for r in range(1, len(data_list) + 1) :
    idx_list = combinations([i for i in range(len(data_list))], r);
for idx in idx_list :
check_dup = Counter(["".join(elements) for elements in zip(*comb)])
if not any(count > 1 for count in check_dup.values()) :
    answer += 1

    return answer
#endif