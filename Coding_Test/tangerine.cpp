#if 0
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int>& a,
    const pair<int, int>& b)
{
    return a.second > b.second;
}

vector<pair<int, int>> sort_map(const map<int, int>& map)
{
    vector<pair<int, int>> vec;

    for (auto& it : map) {
        vec.push_back(it);
    }

    sort(vec.begin(), vec.end(), cmp);

    return vec;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> t_map;

    for (int iter : tangerine)
        t_map[iter] += 1;

    vector<pair<int, int>> t_map_sort = sort_map(t_map);

    for (auto iter : t_map_sort)
    {
        if (k == 0)
            break;

        if (k - iter.second < 0)
        {
            k = 0;
            answer++;
            break;
        }
        k -= iter.second;
        answer++;
    }


    return answer;
}
#endif