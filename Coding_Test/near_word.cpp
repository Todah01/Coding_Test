#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> s_map;

    for (int idx = 0; idx < s.length(); idx++)
    {
        if (s_map.find(s[idx]) == s_map.end())
        {
            answer.push_back(-1);
            s_map.insert({ s[idx], idx });
        }
        else
        {
            answer.push_back(idx - s_map[s[idx]]);
            s_map[s[idx]] = idx;
        }
    }
    return answer;
}