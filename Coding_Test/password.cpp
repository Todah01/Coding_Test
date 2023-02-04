#if 0
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";

    for (char iter : s)
    {
        int idx = index;
        while (idx)
        {
            if (char(iter + 1) > 'z') iter = 'a';
            else iter = char(iter + 1);

            if (find(skip.begin(), skip.end(), iter) == skip.end())
                idx--;
        }

        answer += iter;
    }

    return answer;
}
#endif

#pragma region Using % 'a'
#if 0
#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";

    for (auto v : s)
    {
        int t = 0;
        int c = v - 'a';
        while (t < index)
        {
            c++;
            v = (c % 26) + 'a';
            if (skip.find(v) == string::npos)
            {
                t++;
            }
        }
        answer += v;
    }
    return answer;
}
#endif
#pragma endregion
