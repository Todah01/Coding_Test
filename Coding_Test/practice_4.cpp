#if 0
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;

    for (int i = 0; i < commands.size(); i++)
    {
        temp.clear();

        for (int j = commands[i][0] - 1; j < commands[i][1]; j++)
        {
            temp.push_back(array[j]);
        }

        sort(temp.begin(), temp.end());
        answer.push_back(temp[commands[i][2] - 1]);
    }
    return answer;
}

int main()
{
    vector<int> array = { 1,5,2,6,3,7,4 };
    vector<vector<int>> commands = { {2,5,3},{4,4,1},{1,7,3} };
    vector<int> answer;
    vector<int>::iterator iter;

    answer = solution(array, commands);

    for (iter = answer.begin(); iter != answer.end(); iter++)
    {
        cout << *iter << endl;
    }
}
#endif