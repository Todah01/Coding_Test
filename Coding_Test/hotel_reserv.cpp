#if 0
from datetime import datetime, timedelta

def solution(book_time) :
    answer = 0
    book_list = []
    book_time.sort(key = lambda x : datetime.strptime(x[0], "%H:%M"))

    # print(book_time)

    for i, o in book_time :
in_time = datetime.strptime(i, "%H:%M")
out_time = datetime.strptime(o, "%H:%M") + timedelta(minutes = 10)
book_list.append([in_time, out_time])



return answer

def solution(book_time) :
    heap = [] # �д��� book_time �ð��� ���� ��
    last_out = [-10] # �ش� ���� ������ ��� ���� �ð�.ù �游 ������ - 10������ �ʱ�ȭ
    # ��� ���� ���� �Խǽð��� �������� heappush
    for i, o in book_time :
i, o = converter(i), converter(o)
heappush(heap, (i, o))

# heap ���Ұ� ���� ������
while heap:
now_in, now_out = heappop(heap)
# ���� ���� ���� �濡 �� �� �ִٸ�
if now_in >= last_out[0] + 10: # last_out[0] : ���� ���� ���� �ð�.
heappop(last_out) # �ش� ���� ����ð��� ����
heappush(last_out, now_out) # ������ ����ð��� heappush
else:
heappush(last_out, now_out) # �׷��� �ʴٸ� ���ο� ����(��)�� ����ð����� �߰�

return len(last_out)
#endif