// 1번
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

int solution(int N, int M, vector<vector<int>> city_map) {
    int n = city_map.size();

    vector<pair<int, int>> house, chicken;
    vector<vector<pair<int, int>>> cases;

    for(int i=0; i<n; i++)
        for (int j = 0; j < n; j++)
        {
            if (city_map[i][j] == 1) house.push_back({ i,j });
            else if (city_map[i][j] == 2) chicken.push_back({ i,j });
        }
    
    //for (auto iter : chicken) cout << iter.first << ',' << iter.second << " ";
    //cout << endl;

    int chicken_size = chicken.size();
    vector<bool> comb(chicken_size - M, false);
    comb.insert(comb.end(), M, true); 

    do {
        vector<pair<int,int>> temp;
        for (int k = 0; k < chicken_size; k++) {
            if (comb[k]) temp.push_back({ chicken[k] });
        }
        //for (auto iter : temp) cout << iter.first << ',' << iter.second << " ";
        //cout << endl;
        cases.push_back(temp);
    } while (next_permutation(comb.begin(), comb.end()));

    int chicken_length = INT_MAX;
    for (auto iter : cases)
    {
        int min_all_length = 0;
        for (auto home : house)
        {
            int min_home_length = INT_MAX;
            for (auto number : iter)
            {
                min_home_length = min(min_home_length, abs(home.first - number.first) + abs(home.second - number.second));
            }
            min_all_length += min_home_length;
        }
        chicken_length = min(chicken_length, min_all_length);
    }

    return chicken_length;
}

int main()
{
    vector<vector<int>> city_1 = { {0, 0, 1, 0, 0},
                                   {0, 0, 2, 0, 1},
                                   {0, 1, 2, 0, 0},
                                   {0, 0, 1, 0, 0},
                                   {0, 0, 0, 0, 2},};

    vector<vector<int>> city_2 = { {1, 2, 0, 0, 0},
                                   {1, 2, 0, 0, 0},
                                   {1, 2, 0, 0, 0},
                                   {1, 2, 0, 0, 0},
                                   {1, 2, 0, 0, 0}, };

    vector<vector<int>> city_3 = { {0, 2, 0, 1, 0},
                                   {1, 0, 1, 0, 0},
                                   {0, 0, 0, 0, 0},
                                   {2, 0, 0, 1, 1},
                                   {2, 2, 0, 1, 2}, };

    cout << solution(5, 3, city_1) << endl; // 정답 : 5
    cout << solution(5, 1, city_2) << endl; // 정답 : 11
    cout << solution(5, 2, city_3) << endl; // 정답 : 10
}
#endif

// 2번
#if 0
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> older_bro, younger_bro;

    for (auto iter : topping)
    {
        older_bro[iter] += 1;
    }

    //for (auto iter : older_bro)
    //{
    //    cout << iter.first << ":" << iter.second << endl;
    //}
    for (auto iter : topping)
    {
        older_bro[iter] -= 1;
        if (older_bro[iter] == 0) older_bro.erase(iter);
        younger_bro[iter] += 1;

        if (older_bro.size() == younger_bro.size()) answer++;
    }

    return answer;
}

int main()
{
    cout << solution({ 1, 2, 1, 3, 1, 4, 1, 2 }) << endl; // 정답 : 2
    cout << solution({ 1, 2, 3, 1, 4 }) << endl; // 정답 : 0
}
#endif

// 3번
#if 0
#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {

    vector<int> answer(prices.size());
    stack<int> check;
    int size = prices.size();

    for (int i = 0; i < size; i++)
    {
        while (!check.empty() && prices[check.top()] > prices[i])
        {
            answer[check.top()] = i - check.top();
            check.pop();
        }

        check.push(i);
    }

    while (!check.empty())
    {
        answer[check.top()] = size - check.top() - 1;
        check.pop();
    }

    return answer;
}

int main()
{
    // 정답 : 4 3 1 1 0
    for (auto iter : solution({ 1, 2, 3, 2, 3 }))
    {
        cout << iter << " ";
    }
}
#endif