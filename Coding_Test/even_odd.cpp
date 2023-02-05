#if 0
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> board_to_table(int m, int n, vector<string> board)
{
    vector<string> vertical_board(n);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            vertical_board[j].push_back(board[i][j]);
        }

    for (int i = 0; i < n; i++)
    {
        reverse(vertical_board[i].begin(), vertical_board[i].end());
    }

    return vertical_board;
}


int crash(int m, int n, int cnt, vector<string> vertical_board)
{
    int k = 0;
    int crash_cnt = 0;
    vector<vector<int>> crash_board(n, vector<int>(m));

    //탐색
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m - 1; j++)
        {
            if (vertical_board[i][j] != 'X' && vertical_board[i][j] == vertical_board[i][j + 1] && vertical_board[i][j] == vertical_board[i + 1][j] && vertical_board[i][j] == vertical_board[i + 1][j + 1])
            {
                crash_board[i][j] = 1;
                crash_board[i][j + 1] = 1;
                crash_board[i + 1][j] = 1;
                crash_board[i + 1][j + 1] = 1;
            }
        }

    //변환
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (crash_board[i][j] == 1)
            {
                vertical_board[i][j] = 'X';
            }
        }

    //제거
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vertical_board[i][j - k] == 'X')
            {
                vertical_board[i].erase(vertical_board[i].begin() + j - k);
                cnt++;
                k += 1;
            }
        }
        k = 0;
    }

    //빈공간에 더미값 채워넣기
    for (int i = 0; i < n; i++)
    {
        while (vertical_board[i].size() < m)
        {
            vertical_board[i].push_back('X');
        }
    }

    //재탐색
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m - 1; j++)
        {
            if (vertical_board[i][j] != 'X' && vertical_board[i][j] == vertical_board[i][j + 1] && vertical_board[i][j] == vertical_board[i + 1][j] && vertical_board[i][j] == vertical_board[i + 1][j + 1])
            {
                crash_cnt++;
            }
        }

    if (crash_cnt != 0)
    {
        return crash(m, n, cnt, vertical_board);
    }
    else
    {
        return cnt;
    }

    // for(int i=0; i<n; i++)
    // {
    //     for(int j=0; j<m; j++)
    //     {
    //         cout << vertical_board[i][j];
    //     }
    //     cout << endl;
    // }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int cnt = 0;

    vector<string> vertical_board(n);

    vertical_board = board_to_table(m, n, board);
    answer = crash(m, n, cnt, vertical_board);

    return answer;
}
#endif