#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int cnt = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = i + 1; j < prices.size(); j++)
        {
            if (prices[i] <= prices[j])
            {
                cnt++;
            }
            else
            {
                cnt++;
                break;
            }
        }
        answer.push_back(cnt);
        cnt = 0;
    }
    
    return answer;
}

int main()
{
    vector<int> prices = { 1,2,3,2,3 };
    vector<int> answer;
    vector<int>::iterator iter;

    answer = solution(prices);

    for (iter = answer.begin(); iter != answer.end(); iter++)
    {
        cout << *iter << endl;
    }
}
#endif