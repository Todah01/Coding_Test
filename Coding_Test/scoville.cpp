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

    // 모든 음식의 스코빌 지수를 K이상으로 만들기 위해 섞어야 하는 최소 횟수
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