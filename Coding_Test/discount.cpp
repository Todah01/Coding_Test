#if 0
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> m_want;

    for (int idx = 0; idx < want.size(); idx++)
        m_want[want[idx]] = number[idx];

    for (int idx = 0; idx < discount.size() - 9; idx++)
    {
        map<string, int> m_discnt;
        for (int temp = idx; temp < idx + 10; temp++)
            m_discnt[discount[temp]] += 1;

        if (m_want == m_discnt)
            answer++;
    }

    return answer;
}
#endif

#pragma region Using one map
#if 0
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;
    map<string, int> m;
    for (int i = 0; i < 9; i++)
        m[discount[i]]++;

    for (int i = 9; i < discount.size(); i++)
    {
        m[discount[i]]++;

        bool flag = true;

        for (int j = 0; j < want.size(); j++)
            if (m[want[j]] != number[j])
            {
                flag = false;
                break;
            }

        if (flag == true)
            answer++;

        m[discount[i - 9]]--;
    }
    return answer;
}

#endif
#pragma endregion
