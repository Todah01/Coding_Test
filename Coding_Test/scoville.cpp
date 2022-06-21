#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> temp;

    // ��� ������ ���ں� ������ K�̻����� ����� ���� ����� �ϴ� �ּ� Ƚ��
    for (int iter : scoville) temp.push(iter);

    while (1)
    {
        if (temp.top() >= K) break;
        else if (!temp.empty())
        {
            if (temp.size() >= 2)
            {
                int n1 = temp.top();
                temp.pop();
                int n2 = temp.top();
                temp.pop();

                temp.push(n1 + (n2 * 2));
                answer++;
            }
            else
            {
                if (temp.top() >= K) break;
                else
                {
                    answer = -1;
                    break;
                }
            }
        }
    }

    return answer;
}
#endif