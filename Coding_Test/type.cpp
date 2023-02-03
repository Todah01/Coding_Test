#if 0
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char, int> result;
    vector<string> types = { "RT", "CF", "JM", "AN" };

    for (int idx = 0; idx < survey.size(); idx++)
    {
        if (choices[idx] < 4)
            result[survey[idx][0]] += 4 - choices[idx];
        else
            result[survey[idx][1]] += choices[idx] - 4;
    }

    for (auto type : types)
    {
        if (result[type[0]] >= result[type[1]])
            answer += type[0];
        else
            answer += type[1];
    }

    return answer;
}
#endif