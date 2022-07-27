//1¹ø
#if 0
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int cal_time(string record)
{
    int time = stoi(record.substr(0, 2));
    int minite = stoi(record.substr(3, 2));

    return time * 60 + minite;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> check_in, time_board;

    int basic_time = fees[0];
    int basic_fee = fees[1];
    int unit_time = fees[2];
    int unit_fee = fees[3];

    for (int i = 0; i < records.size(); i++)
    {
        // cout << records[i].substr(11,3) << endl;
        if (records[i].substr(11, 3) == "IN")
        {
            check_in.insert({ records[i].substr(6,4) ,cal_time(records[i]) });
        }
        else
        {
            time_board[records[i].substr(6, 4)] += cal_time(records[i]) - check_in[records[i].substr(6, 4)];
            check_in.erase(records[i].substr(6, 4));
        }
    }

    for (auto record : check_in)
    {
        time_board[record.first] += 1439 - record.second;
    }

    for (auto fee : time_board)
    {
        if (fee.second <= basic_time) answer.push_back(basic_fee);
        else
        {
            int cal_fee = ((fee.second - basic_time) + unit_time - 1) / unit_time;
            answer.push_back(basic_fee + (cal_fee * unit_fee));
        }
    }

    return answer;
}
#endif

//2¹ø
#if 0
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    queue<int> q;

    for (int i = 0; i < progresses.size(); i++) {
        int d = (100 - progresses[i]) / speeds[i];
        if ((progresses[i] + d * speeds[i]) != 100) d++;
        days.push_back(d);
    }

    q.push(days[0]);
    for (int i = 1; i < days.size(); i++) {
        if (q.front() >= days[i]) {
            q.push(days[i]);
        }
        else {
            answer.push_back(q.size());
            while (!q.empty()) q.pop();
            q.push(days[i]);
        }
    }

    if (!q.empty()) answer.push_back(q.size());

    return answer;
}
#endif