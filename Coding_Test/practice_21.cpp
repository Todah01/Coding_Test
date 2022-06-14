#if 0
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    unordered_map<string, int> foodmaps[11];
    int maxcnt[11] = { 0 };

    for (auto order : orders)
    {
        sort(order.begin(), order.end());
        for (int cnt : course)
        {
            if (order.size() < cnt) continue;

            vector<bool> check(order.size() - cnt, false);
            check.insert(check.end(), cnt, true);

            do {
                string temp = "";
                for (int k = 0; k < order.size(); k++)
                {
                    if (check[k]) temp += order[k];
                }
                // cout << temp << " ";
                foodmaps[temp.size()][temp]++;
                maxcnt[temp.size()] = max(maxcnt[temp.size()], foodmaps[temp.size()][temp]);
            } while (next_permutation(check.begin(), check.end()));
            // cout << endl;
        }
        // cout << endl;
    }

    for (int cnt : course)
    {
        for (auto item : foodmaps[cnt])
        {
            if (item.second >= 2 && item.second == maxcnt[cnt])
                answer.push_back(item.first);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}
#endif