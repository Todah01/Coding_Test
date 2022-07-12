#if 0
#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    queue<int> check;
    int idx = 0;

    for (int i = 0; i < prices.size(); i++) check.push(prices[i]);

    while (!check.empty())
    {
        idx++;
        int non_drop_cnt = 0;
        int cur_price = check.front();
        check.pop();

        for (int i = idx; i < prices.size(); i++)
        {
            if (cur_price > prices[i])
            {
                non_drop_cnt++;
                break;
            }
            non_drop_cnt++;
        }
        answer.push_back(non_drop_cnt);
    }

    return answer;
}
#endif