#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<string> board) {
    int O = 0, X = 0;
    for (auto iter : board) {
        O += count(iter.begin(), iter.end(), 'O');
        X += count(iter.begin(), iter.end(), 'X');
    }

    if (0 <= O - X && O - X <= 1) {
        vector<string> rotate_board;
        vector<string> diagonal;
        int win_cnt_O = 0, win_cnt_X = 0;

        for (int i = 0; i < 3; i++) {
            string temp = "";

            temp += board[0][i];
            temp += board[1][i];
            temp += board[2][i];

            rotate_board.push_back(temp);
        }

        string diagonal_1;
        string diagonal_2;

        diagonal_1 += board[0][0];
        diagonal_1 += board[1][1];
        diagonal_1 += board[2][2];

        diagonal_2 += board[0][2];
        diagonal_2 += board[1][1];
        diagonal_2 += board[2][0];

        diagonal.push_back(diagonal_1);
        diagonal.push_back(diagonal_2);

        for (int i = 0; i < 3; i++) {
            if (board[i] == "OOO" || rotate_board[i] == "OOO")
                win_cnt_O++;
            if (board[i] == "XXX" || rotate_board[i] == "XXX")
                win_cnt_X++;
        }

        win_cnt_O += count(diagonal.begin(), diagonal.end(), "OOO");
        win_cnt_X += count(diagonal.begin(), diagonal.end(), "XXX");

        if (win_cnt_O && win_cnt_X) return 0;
        if (win_cnt_O && win_cnt_X == 0 && O == X) return 0;
        if (win_cnt_X && win_cnt_O == 0 && O != X) return 0;

        return 1;
    }

    return 0;
}
#endif