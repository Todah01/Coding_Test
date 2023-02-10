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
            vertical_board[j].push_back(board[i][j]);

    for (int i = 0; i < n; i++)
        reverse(vertical_board[i].begin(), vertical_board[i].end());

    return vertical_board;
}


int crash(int m, int n, int cnt, vector<string> vertical_board)
{
    int k = 0;
    int crash_cnt = 0;
    vector<vector<int>> crash_board(n, vector<int>(m));

    //Ž��
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m - 1; j++)
        {
            if (vertical_board[i][j] != '!' && vertical_board[i][j] == vertical_board[i][j + 1] && vertical_board[i][j] == vertical_board[i + 1][j] && vertical_board[i][j] == vertical_board[i + 1][j + 1])
            {
                crash_board[i][j] = 1;
                crash_board[i][j + 1] = 1;
                crash_board[i + 1][j] = 1;
                crash_board[i + 1][j + 1] = 1;
            }
        }

    //��ȯ
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (crash_board[i][j] == 1)
                vertical_board[i][j] = '!';
        }

    //����
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vertical_board[i][j - k] == '!')
            {
                vertical_board[i].erase(vertical_board[i].begin() + j - k);
                cnt++;
                k += 1;
            }
        }
        k = 0;
    }

    //������� ���̰� ä���ֱ�
    for (int i = 0; i < n; i++)
    {
        while (vertical_board[i].size() < m)
        {
            vertical_board[i].push_back('!');
        }
    }

    //��Ž��
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m - 1; j++)
        {
            if (vertical_board[i][j] != '!' && vertical_board[i][j] == vertical_board[i][j + 1] && vertical_board[i][j] == vertical_board[i + 1][j] && vertical_board[i][j] == vertical_board[i + 1][j + 1])
            {
                crash_cnt++;
            }
        }

    if (crash_cnt != 0)
        return crash(m, n, 0, vertical_board);
    else
        return cnt;
}

int solution(int m, int n, vector<string> board) {
    vector<string> vertical_board(n);
    vertical_board = board_to_table(m, n, board);
    return crash(m, n, 0, vertical_board);
}
#endif