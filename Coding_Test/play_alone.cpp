#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    return a.size() > b.size();
}

int solution(vector<int> cards) {
    vector<vector<int>> answer;

    for (int idx = 0; idx < cards.size(); idx++)
    {
        vector<int> temp;
        while (find(temp.begin(), temp.end(), cards[idx]) == temp.end())
        {
            temp.push_back(cards[idx]);
            idx = cards[idx] - 1;
        }

        sort(temp.begin(), temp.end());

        if (find(answer.begin(), answer.end(), temp) == answer.end())
            answer.push_back(temp);
        else
        {
            temp.clear();
            answer.push_back(temp);
        }
    }

    sort(answer.begin(), answer.end(), cmp);

    return answer[0].size() * answer[1].size();
}
#endif

#pragma region Using While
#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    int n = cards.size();  //카드의 수
    vector<int> visited(n, 0);
    vector<int> temp;
    for (int i = 0;i < n;i++)
    {
        int n = 0;
        int j = i;
        while (visited[j] == 0)
        {
            visited[j] = 1;
            j = cards[j] - 1;  // j는 인덱스 처럼 적용
            n++;
        }
        if (n != 0)
            temp.push_back(n);
    }
    sort(temp.rbegin(), temp.rend());

    if (temp.size() == 1)
        answer = 0;
    else
        answer = temp[0] * temp[1];
    return answer;
}
#endif
#pragma endregion

#pragma region Using recursion
#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visited;
void Check(int start, vector<int> cards, vector<int>& tmp)
{
    if (visited[start])
        return;
    visited[start] = true;
    tmp.push_back(start + 1);
    int next = cards[start];
    Check(next - 1, cards, tmp);
}

int solution(vector<int> cards) {
    int answer = 0;

    int maxVal = 0;

    for (int i = 0;i < cards.size();i++)
    {
        vector<int> group1;
        visited = vector<bool>(cards.size(), false);

        Check(i, cards, group1);
        for (int j = 0;j < cards.size();j++)
        {
            vector<int> group2;
            if (i == j || visited[j])
                continue;
            Check(j, cards, group2);
            int _size = group1.size() * group2.size();
            maxVal = max(maxVal, _size);
        }
    }

    answer = maxVal;
    return answer;
}
#endif
#pragma endregion
