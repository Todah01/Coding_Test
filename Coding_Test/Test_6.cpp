//1번 - 1
#if 0
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int cnt = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            answer += ' ';
            cnt = 0;
        }
        else if (cnt % 2 == 1)
        {
            answer += tolower(s[i]);
            cnt++;
        }
        else
        {
            answer += toupper(s[i]);
            cnt++;
        }
    }

    return answer;
}
#endif

//1번 - 2
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    string stringBuffer;
    istringstream ss(s);
    vector<string> temp;

    while (getline(ss, stringBuffer, ' ')) {
        temp.push_back(stringBuffer);
    }

    for (auto iter : temp)
    {
        for (int i = 0; i < iter.size(); i++)
        {
            if (i % 2 == 1) answer += tolower(iter[i]);
            else answer += toupper(iter[i]);
        }
        answer += ' ';
    }

    return answer;
}
#endif

//2번
#if 0
#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    stack<int> basket;
    vector<stack<int>> vertical_board(board.size());

    for (int i = board.size() - 1; i >= 0; i--)
        for (int j = board[i].size() - 1; j >= 0; j--)
            if (board[i][j] != 0) vertical_board[j].push(board[i][j]);

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
        //cout << basket.top();
    }

    return answer;
}
}
#endif

//3번
#if 0
using namespace std;

long long solution(int w, int h) {
    long long answer = 1;

    return answer;
}
#endif