#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool badValue(char x)
{
    if (x == '0')
    {
        return true;
    }

    return false;
}

vector<char> create_copy(vector<char> const& vec)
{
    vector<char> v(vec.begin(), vec.end());
    return v;
}

string solution(string X, string Y) {
    string answer = "";

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    vector<char> buff(X.size() + Y.size());
    auto iter = set_intersection(X.begin(), X.end(), Y.begin(), Y.end(), buff.begin());
    buff.erase(iter, buff.end());

    if (buff.empty())
        return "-1";
    else
    {
        vector<char> temp = create_copy(buff);
        temp.erase(remove_if(temp.begin(), temp.end(), badValue), temp.end());
        if (temp.empty())
            return "0";
        else
        {
            sort(buff.begin(), buff.end(), greater<>());
            for (auto iter : buff)
                answer += iter;
        }
    }

    return answer;
}
#endif

#pragma region Using Map
#if 0

3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string X, string Y)
{
    string answer = "";
    map<char, int> mx;
    for (char c : X) mx[c]++;
    map<char, int> my;
    for (char c : Y) my[c]++;
    for (int i = 9; i >= 0; i--)
    {
        int num = min(mx[i + '0'], my[i + '0']);
        for (int j = 0; j < num; j++) answer += i + '0';
    }
    if (answer == "") answer = "-1";
    else if (answer[0] == '0' && answer.size() > 1) answer = "0";
    return answer;
}
#endif
#pragma endregion
