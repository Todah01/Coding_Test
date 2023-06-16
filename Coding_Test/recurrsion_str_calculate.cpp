#if 0
import re
from itertools import permutations

def solution(expression) :
    answer = 0
    operators = ['+', '-', '*']
    for operator in operators :
if operator not in expression :
operators.remove(operator)

split_result = re.findall(r'\d+|[-+*]', expression)

operator_perms = permutations(operators)
for operator_perm in operator_perms :
cpy_result = split_result
for oper in operator_perm :
temp_result = []
for idx in range(len(cpy_result)) :
    if cpy_result[idx] == oper :
        temp_result.append(str(eval(''.join(cpy_result[idx - 1:idx + 2]))))
    else :
        temp_result.append(cpy_result[idx])
        cpy_result = temp_result
        print(temp_result)

        return answer
#endif