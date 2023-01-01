#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer, hall_of_fame;

    for (auto s : score)
    {
        hall_of_fame.push_back(s);
        sort(hall_of_fame.begin(), hall_of_fame.end(), greater<int>());
        if (hall_of_fame.size() > k) hall_of_fame.pop_back();
        answer.push_back(hall_of_fame.back());
    }

    return answer;
}