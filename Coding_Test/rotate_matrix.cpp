#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int field[101][101];

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            field[i][j] = (i - 1) * columns + j;
        }
    }


    for (int i = 0; i < (int)queries.size(); i++)
    {
        int mini = field[queries[i][0]][queries[i][1]];
        int temp = field[queries[i][0]][queries[i][1]];

        for (int j = queries[i][0]; j < queries[i][2]; j++)
        {
            field[j][queries[i][1]] = field[j + 1][queries[i][1]];
            mini = min(mini, field[j][queries[i][1]]);
        }

        for (int j = queries[i][1]; j < queries[i][3]; j++)
        {
            field[queries[i][2]][j] = field[queries[i][2]][j + 1];
            mini = min(mini, field[queries[i][2]][j]);
        }

        for (int j = queries[i][2]; j > queries[i][0]; j--)
        {
            field[j][queries[i][3]] = field[j - 1][queries[i][3]];
            mini = min(mini, field[j][queries[i][3]]);
        }

        for (int j = queries[i][3]; j > queries[i][1]; j--)
        {
            field[queries[i][0]][j] = field[queries[i][0]][j - 1];
            mini = min(mini, field[queries[i][0]][j]);
        }

        field[queries[i][0]][queries[i][1] + 1] = temp;

        answer.push_back(mini);
    }


    return answer;
}
#endif