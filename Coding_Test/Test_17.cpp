// 1번
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

bool isCorrect(string p, int* pos)
{
    bool ret = true;
    int left_bracket_cnt = 0;
    int right_bracket_cnt = 0;
    stack<char> check;

    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] == '(')
        {
            left_bracket_cnt++;
            check.push(p[i]);
        }
        else
        {
            right_bracket_cnt++;
            if (check.empty()) ret = false;
            else check.pop();
        }

        if (left_bracket_cnt == right_bracket_cnt)
        {
            *pos = i + 1;
            return ret;
        }
    }
}

string solution(string p) {
    // 1번
    if (p.empty()) return p;

    string answer = "";

    int pos;
    bool correct = isCorrect(p, &pos);

    // 2번
    string u = p.substr(0, pos);
    string v = p.substr(pos, p.size() - pos);

    // cout << u << " " << v;

    //3번
    if (correct)
    {
        return u + solution(v);
    }

    //4번
    answer = "(" + solution(v) + ")";
    for (int i = 1; i < u.size() - 1; i++)
    {
        if (u[i] == '(') answer += ")";
        else answer += "(";
    }

    return answer;
}

int main()
{
    cout << solution("(()())()");
    cout << solution(")(");
    cout << solution("()))((()");
}
#endif

// 2번
#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    return answer;
}

int main()
{
    cout << solution({ "AN", "CF", "MJ", "RT", "NA" }, { 5,3,2,7,5 });
    cout << solution({ "TR", "RT", "TR" }, { 7,1,3 });
}
#endif