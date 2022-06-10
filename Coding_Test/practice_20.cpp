#if 0
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> temp;

    // 스택에 하나씩 넣으면서 짝지어지는 함수가 있는지 확인
    for (int i = 0; i < s.size(); i++)
    {
        if (!temp.empty() && temp.top() == s[i]) temp.pop();
        else temp.push(s[i]);
    }

    answer = (temp.empty()) ? 1 : 0;

    return answer;
}
#endif