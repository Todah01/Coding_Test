#if 0
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string>> set_record;
    map<string, string> check_nick;

    for (auto iter : record)
    {
        vector<string> check_record;
        stringstream ss(iter);
        string temp;
        pair<string, string> result;

        while (getline(ss, temp, ' ')) {
            check_record.push_back(temp);
        }

        if (check_record[0] == "Enter")
        {
            check_nick[check_record[1]] = check_record[2];
            result.first = check_record[1];
            result.second = "님이 들어왔습니다.";
            set_record.push_back(result);
        }
        else if (check_record[0] == "Leave")
        {
            result.first = check_record[1];
            result.second = "님이 나갔습니다.";
            set_record.push_back(result);
        }
        else if (check_record[0] == "Change")
        {
            check_nick[check_record[1]] = check_record[2];
        }
    }

    for (auto iter : set_record)
        answer.push_back(check_nick[iter.first] + iter.second);

    return answer;
}
#endif

#pragma region Using State
#if 0
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    map<string, string> m;  //id,nick
    vector<pair<int, string>> v;//state,id
    for (int i = 0; i < record.size(); i++)
    {
        int state = 0;//0:enter, 1:leave, 2:change;
        string id = "";
        string nick = "";

        int idx = 6;
        //enter
        if (record[i][0] == 'E') {}
        //leave
        else if (record[i][0] == 'L')
        {
            state = 1;
        }
        //change
        else
        {
            state = 2;
            idx++;
        }

        for (; idx < record[i].size() && record[i][idx] != ' '; idx++)
        {
            id += record[i][idx];
        }
        idx++;

        if (state != 1)
        {
            for (; idx < record[i].size(); idx++)
            {
                nick += record[i][idx];
            }

            m[id] = nick;
        }

        if (state != 2)
        {
            v.push_back(pair<int, string>(state, id));
        }
    }

    vector<string> answer(v.size());
    for (int i = 0; i < v.size(); i++)
    {
        string s = "";
        int state = v[i].first;
        string id = v[i].second;
        string nick = m[v[i].second];
        s += nick + "님이 ";
        if (state == 0)
        {
            s += "들어왔습니다.";
        }
        else
        {
            s += "나갔습니다.";
        }

        answer[i] = s;
    }

    return answer;
}
#endif
#pragma endregion
