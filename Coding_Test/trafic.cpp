#if 0
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int convert_to_ms(string line)
{
    string time_h = line.substr(11, 2);
    string time_m = line.substr(14, 2);
    string time_s = line.substr(17, 6);
    time_s.erase(time_s.begin() + 2, time_s.begin() + 3);

    int h = stoi(time_h) * 60 * 60 * 1000;
    int m = stoi(time_m) * 60 * 1000;
    int s = stoi(time_s);

    return h + m + s;
}

int solution(vector<string> lines) {
    int answer = 0;
    vector<int> end, start;

    for (int i = 0; i < lines.size(); i++)
    {
        string line = lines[i];
        int duration_time = stod(line.substr(24, line.size() - 25)) * 1000;
        int end_time = convert_to_ms(line);

        end.push_back(end_time);
        start.push_back(end_time - duration_time + 1);
    }

    for (int i = 0; i < lines.size(); i++)
    {
        int end_time = end[i] + 1000;
        int cnt = 0;

        for (int j = i; j < lines.size(); j++)
        {
            if (start[j] < end_time) cnt++;
        }

        answer = max(answer, cnt);
    }

    return answer;
}
#endif