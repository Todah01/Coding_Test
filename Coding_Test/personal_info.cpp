#if 0
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> terms_map;
    int today_year = stoi(today.substr(0, 4));
    int today_month = stoi(today.substr(5, 2));
    int today_day = stoi(today.substr(8, 2));
    int today_value = (today_year * 12 * 28) + (today_month * 28) + today_day;

    for (auto iter : terms)
        terms_map[iter[0]] += stoi(iter.substr(2));

    for (int idx = 0; idx < privacies.size(); idx++)
    {
        int cur_year = stoi(privacies[idx].substr(0, 4));
        int cur_month = stoi(privacies[idx].substr(5, 2));
        int cur_day = stoi(privacies[idx].substr(8, 2));
        int cur_term = terms_map[privacies[idx].back()];

        if (cur_month + cur_term > 12)
        {
            cur_year = (cur_month + cur_term) % 12 == 0 ?
                cur_year += (cur_month + cur_term) / 12 - 1 : cur_year += (cur_month + cur_term) / 12;
        }
        cur_month = (cur_month + cur_term) % 12 == 0 ? 12 : (cur_month + cur_term) % 12;

        if (cur_day - 1 == 0)
        {
            cur_month = cur_month - 1 == 0 ? cur_year -= 1, cur_month = 12 : cur_month -= 1, cur_month;
            cur_day = 28;
        }
        else
            cur_day -= 1;

        int cur_value = (cur_year * 12 * 28) + (cur_month * 28) + cur_day;

        if (today_value > cur_value)
            answer.push_back(idx + 1);
    }

    return answer;
}
#endif

#pragma region Using Valuable
#if 0
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> terms_map;
    int today_year = stoi(today.substr(0, 4));
    int today_month = stoi(today.substr(5, 2));
    int today_day = stoi(today.substr(8, 2));
    int today_value = (today_year * 12 * 28) + (today_month * 28) + today_day;

    for (auto iter : terms)
        terms_map[iter[0]] += stoi(iter.substr(2));

    for (int idx = 0; idx < privacies.size(); idx++)
    {
        int cur_year = stoi(privacies[idx].substr(0, 4));
        int cur_month = stoi(privacies[idx].substr(5, 2));
        int cur_day = stoi(privacies[idx].substr(8, 2));
        int cur_term = terms_map[privacies[idx].back()];

        int cur_value = (cur_year * 12 * 28) + (cur_month * 28) + cur_day + (cur_term * 28) - 1;

        if (today_value > cur_value)
            answer.push_back(idx + 1);
    }

    return answer;
}
#endif
#pragma endregion
