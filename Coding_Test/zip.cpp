#if 0
#include <string>
#include <vector>

using namespace std;

int search(vector<string>& dictionary, string msg)
{
    int len = dictionary.size();
    for (int i = 1; i < len; i++)
    {
        if (msg == dictionary[i])
            return i;
    }
    return -1;
}

vector<int> solution(string msg)
{
    vector<int> answer;
    int len = msg.length();
    vector<string> dictionary = { "-1" };

    for (int i = 0; i < 26; i++)
    {
        dictionary.push_back(string(1, 'A' + i));
    }

    int cur = 0;
    int checkLen = 1;
    int idx = -1;

    while (true)
    {
        string str = msg.substr(cur, checkLen);
        int tmp = search(dictionary, str);

        if (tmp > 0)//hit
        {
            idx = tmp;
            checkLen++;
            if (cur + checkLen - 1 == len)
            {
                answer.push_back(idx);
                break;
            }
        }
        else//miss
        {
            answer.push_back(idx);
            dictionary.emplace_back(str);
            cur += checkLen - 1;
            checkLen = 1;
            idx = -1;
        }
    }
    return answer;
}

#endif

#pragma region Using map
#if 0
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> ans;
    map<string, int> mymap;
    string str = "";
    for (int i = 0; i < 26; ++i) {
        str += (i + 65);
        mymap[str.substr(i, 1)] = i + 1;
    }
    for (int i = 0; i < msg.size();) {
        str = "";
        while (i < msg.size() && mymap.find(str + msg[i]) != mymap.end())
            str += msg[i++];
        ans.push_back(mymap[str]);
        if (i < msg.size()) mymap[str + msg[i]] = mymap.size() + 1;
    }
    return ans;
}
#endif
#pragma endregion
