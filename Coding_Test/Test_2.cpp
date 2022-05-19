//1¹ø - 1
#if 0
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    vector<string> temp;
    unordered_map<string, vector<string>> defendant;
    unordered_map<string, int> accused;

    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());

    for (int i = 0; i < id_list.size(); i++)
    {
        defendant.insert(make_pair(id_list[i], temp));
        accused.insert(make_pair(id_list[i], 0));
    }

    for (int i = 0; i < report.size(); i++)
    {
        string s1, s2;
        stringstream ss(report[i]);
        ss >> s1 >> s2;

        defendant[s1].push_back(s2);
        accused[s2] += 1;
        ss.str("");
    }

    for (pair<string, int> atom : accused)
    {
        if (atom.second >= k)
        {
            temp.push_back(atom.first);
        }
    }
    
    for (pair<string, vector<string>> atom : defendant)
    {
        int cnt = 0;

        for (string val_d : atom.second)
        {
            for (string val_t : temp)
            {
                if (val_d == val_t)
                {
                    cnt += 1;
                }
            }
        }

        answer.push_back(cnt);
    }

    return answer;
}

int main()
{
    vector<string> id_list = { "nam","eun","jin","hyun" };
    vector<string> report = { "nam eun","jin eun","eun hyun","nam hyun","jin nam" };

    vector<int> answer;
    vector<int>::iterator iter;

    answer = solution(id_list, report, 2);

    for (iter = answer.begin(); iter != answer.end(); iter++)
    {
        cout << *iter << endl;
    }
}
#endif

//1¹ø - 2
#if 0
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);

    unordered_map<string, int> idx_map;
    for (int i = 0; i < id_list.size(); ++i) idx_map[id_list[i]] = i;

    unordered_map<string, set<string>> report_map;
    stringstream ss;
    for (auto rep : report) {
        ss.str(rep);
        string first, second;
        ss >> first >> second;
        report_map[second].insert(first);

        ss.clear();
    }

    for (auto it : report_map)
    {
        if (it.second.size() >= k)
        {
            for (auto set_it : it.second)
            {
                int idx = idx_map[set_it];
                answer[idx]++;
            }
        }
    }

    return answer;
}
#endif

//2¹ø
#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int temp = (brown - 4) / 2;
    for (int i = 1; i <= yellow; i++)
    {
        if (yellow % i == 0)
        {
            if (yellow / i + i == temp)
            {
                answer.push_back((yellow / i) + 2);
                answer.push_back(i + 2);
                break;
            }
        }
    }
    sort(answer.begin(), answer.end());
    reverse(answer.begin(), answer.end());
    return answer;
}
#endif