#if 0
def solution(storey) :
    answer = 0
    while storey > 0:
storey, remainder = divmod(storey, 10)
if remainder < 5 :
    answer += remainder
    elif remainder > 5 :
    answer += 10 - remainder
    storey += 1
    elif remainder == 5 :
    if storey % 10 < 5 :
        answer += remainder
        elif storey % 10 >= 5 :
        answer += 10 - remainder
        storey += 1

        return answer
#endif