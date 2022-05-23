#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int test_check(vector<int> answers, vector<int> numbers)
{
    int i = 0, k = 0, cnt = 0;

    while (1)
    {
        if (answers[i] == numbers[k])
        {
            cnt++;
        }

        i++;
        if (k == numbers.size() - 1) k = 0;
        else k++;

        if (i == answers.size())
        {
            return cnt;
        }
    }
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> test_taker;
    vector<int> number_1 = { 1,2,3,4,5 };
    vector<int> number_2 = { 2,1,2,3,2,4,2,5 };
    vector<int> number_3 = { 3,3,1,1,2,2,4,4,5,5 };

    test_taker.push_back(test_check(answers, number_1));
    test_taker.push_back(test_check(answers, number_2));
    test_taker.push_back(test_check(answers, number_3));

    int max = *max_element(test_taker.begin(), test_taker.end());

    for (int n = 0; n < test_taker.size(); n++)
    {
        if (test_taker[n] == max) answer.push_back(n + 1);
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    vector<int> answers = { 1,3,2,4,2 };
    vector<int> answer;
    vector<int>::iterator iter;

    answer = solution(answers);

    for (iter = answer.begin(); iter != answer.end(); iter++)
    {
        cout << *iter << endl;
    }
}
#endif