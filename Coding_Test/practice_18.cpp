#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(const pair<int, double>& a, const pair<int, double>& b)
{
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> temp;

    double stage_size = stages.size();

    for (int i = 1; i < N + 1; i++)
    {
        double cnt = count(stages.begin(), stages.end(), i);

        if (stage_size != 0)
        {
            temp.push_back({ i, cnt / stage_size });
            stage_size -= cnt;
        }
        else
        {
            temp.push_back({ i, 0 });
        }
    }

    sort(temp.begin(), temp.end(), cmp);

    for (auto& iter : temp)
    {
        answer.push_back(iter.first);
    }
    return answer;
}
#endif