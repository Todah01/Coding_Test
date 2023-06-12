#if 0
from datetime import datetime

def solution(m, musicinfos) :
    answer = ''
    temp_zero = int(datetime.strptime(musicinfos[0].split(',')[0], "%H:%M").strftime("%H%M"))
    print(temp_zero)
    temp_one = int(datetime.strptime(musicinfos[0].split(',')[1], "%H:%M").strftime("%H%M"))
    print(temp_one)
    temp_diff = temp_one - temp_zero
    print(temp_diff)
    return answer
#endif