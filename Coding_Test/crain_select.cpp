#if 0
#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<stack<int>> vertical_board(board.size());
    stack<int> basket;

    for (int i = 0; i < board.size(); i++)
        for (int j = board[i].size() - 1; j >= 0; j--)
            if (board[j][i] != 0) vertical_board[i].push(board[j][i]);

    // for(int i=0; i<vertical_board.size(); i++)
    // {
    //     while(!vertical_board[i].empty())
    //     {
    //         cout << vertical_board[i].top();
    //         vertical_board[i].pop();
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < moves.size(); i++)
    {
        if (!vertical_board[moves[i] - 1].empty())
        {
            if (!basket.empty() && basket.top() == vertical_board[moves[i] - 1].top())
            {
                basket.pop();
                vertical_board[moves[i] - 1].pop();
                answer += 2;
            }
            else
            {
                basket.push(vertical_board[moves[i] - 1].top());
                vertical_board[moves[i] - 1].pop();
            }
        }
    }

    return answer;
}
#endif