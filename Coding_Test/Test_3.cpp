//1��
#if 1
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    for (int i = 0; i < absolutes.size(); i++)
    {
        if (signs[i]) answer += absolutes[i];
        else answer -= absolutes[i];
    }
    return answer;
}
#endif

//2��
#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> check;

    for (int i = 0; i < n; i++) check.push_back(1);
    for (auto& iter : lost) check[iter - 1] -= 1;
    for (auto& iter : reserve) check[iter - 1] += 1;

    for (int i = 0; i < n; i++)
    {
        if (check[i] == 0)
        {
            if (i == 0)
            {
                if (check[i + 1] == 2)
                {
                    check[i + 1] -= 1;
                    check[i] += 1;
                }
            }
            else if (i == n)
            {
                if (check[i - 1] == 2)
                {
                    check[i - 1] -= 1;
                    check[i] += 1;
                }
            }
            else
            {
                if (check[i - 1] == 2)
                {
                    check[i - 1] -= 1;
                    check[i] += 1;
                }
                else if (check[i + 1] == 2)
                {
                    check[i + 1] -= 1;
                    check[i] += 1;
                }
            }
        }
    }

    for (auto& iter : check) if (iter > 0) answer++;

    return answer;
}
#endif

//3��
#if 0
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> s;

    int size = prices.size(); // ��� size�� ����ϴ� �ͺ��� ��������� �����ϸ� ��ü �Լ� ó�� �ð� ����

    for (int i = 0; i < size; ++i) {
        while (!s.empty() && prices[s.top()] > prices[i]) { // ������ �پ����ٸ�
            answer[s.top()] = i - s.top(); // ���� �ð� - ��� �ð�
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty()) {
        answer[s.top()] = size - s.top() - 1; // ���� �ð� - ��� �ð�
        s.pop();
    }

    return answer;
}
#endif