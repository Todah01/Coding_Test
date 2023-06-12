#if 0
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> board;

void dfs(int a, int b, vector<int>& answer, int size) {
    int x = a;
    int y = b;
    int target = board[x][y];

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (board[x + i][y + j] != target) {
                dfs(x, y, answer, size / 2);
                dfs(x, y + size / 2, answer, size / 2);
                dfs(x + size / 2, y, answer, size / 2);
                dfs(x + size / 2, y + size / 2, answer, size / 2);
                return;
            }

    answer[target]++;
    return;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    board = arr;
    dfs(0, 0, answer, arr.size());
    return answer;
}
#endif

#if 0
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    map<int, vector<int>> dir = { pair<int, vector<int>>(0, {1,0}),
                                  pair<int, vector<int>>(1, {0,1}),
                                  pair<int, vector<int>>(2, {-1,-1}) };
    vector<vector<int>> total_slug;
    for (int i = 0; i < n; i++) {
        vector<int> temp(i + 1, 0);
        total_slug.push_back(temp);
    }

    int row = -1;
    int col = 0;
    int number = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            vector<int> tmp_dir = dir[i % 3];
            row += tmp_dir[0];
            col += tmp_dir[1];
            total_slug[row][col] = number;
            number++;
        }
    }

    for (auto iter : total_slug) {
        answer.insert(answer.end(), iter.begin(), iter.end());
    }

    return answer;
}
#endif