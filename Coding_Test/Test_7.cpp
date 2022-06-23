//1¹ø
#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int comp;

bool cmp(string x, string y)
{
    if (x[comp] == y[comp]) return x <= y;
    return x[comp] < y[comp];
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    comp = n;
    sort(strings.begin(), strings.end(), cmp);

    answer = strings;

    return answer;
}
#endif

//2¹ø
#if 0
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int idx = 0;
    int score[3] = { 0, };

    for (int i = 0; i < dartResult.size(); i++)
    {
        if (dartResult[i] >= '0' && dartResult[i] <= '9')
        {
            if (dartResult[i - 1] == '1' && dartResult[i] == '0')
            {
                score[idx - 1] = 10;
            }
            else
            {
                score[idx] = dartResult[i] - '0';
                idx++;
            }
        }

        if (dartResult[i] == 'S') score[idx - 1] = pow(score[idx - 1], 1);
        else if (dartResult[i] == 'D') score[idx - 1] = pow(score[idx - 1], 2);
        else if (dartResult[i] == 'T') score[idx - 1] = pow(score[idx - 1], 3);

        if (dartResult[i] == '#') score[idx - 1] *= -1;
        else if (dartResult[i] == '*')
        {
            if (idx == 0) score[idx - 1] *= 2;
            else
            {
                score[idx - 2] *= 2;
                score[idx - 1] *= 2;
            }
        }
    }

    for (int iter : score) answer += iter;

    return answer;
}
#endif

//3¹ø
#if 0
#include<vector>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    return answer;
}
#endif