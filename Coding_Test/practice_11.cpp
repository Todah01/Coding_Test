#if 0
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;

    for (auto& iter : commands)
    {
        for (int i = iter[0] - 1; i <= iter[1] - 1; i++)
        {
            temp.push_back(array[i]);
        }

        sort(temp.begin(), temp.end());

        answer.push_back(temp[iter[2] - 1]);
        temp.clear();
    }
    return answer;
}

int main()
{
    vector<int> answer = { 1, 5, 2, 6, 3, 7, 4 };
    vector<vector<int>> commands = { {2, 5, 3} ,{4, 4, 1},{1, 7, 3} };

    for (auto& iter : solution(answer, commands))
    {
        cout << iter << endl;
    }
}
#endif