#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int row = maps.size();
    int col = maps[0].length();
    vector<int> dx = { 1, -1, 0, 0 };
    vector<int> dy = { 0, 0, -1, 1 };
    vector<int> col_visited(col, 0);
    vector<vector<int>> visited(row, col_visited);

    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++)
            if (maps[r][c] != 'X' && visited[r][c] != 1) {
                queue<pair<int, int>> Q;
                Q.push({ r, c });
                visited[r][c] = 1;
                int food = maps[r][c] - '0';

                while (!Q.empty()) {
                    int cr = Q.front().first;
                    int cc = Q.front().second;
                    Q.pop();

                    for (int idx = 0; idx < 4; idx++) {
                        int dr = cr + dx[idx];
                        int dc = cc + dy[idx];
                        if (dr >= 0 && dr < row && dc >= 0 && dc < col && maps[dr][dc] != 'X') {
                            if (!visited[dr][dc]) {
                                visited[dr][dc] = 1;
                                food += maps[dr][dc] - '0';
                                Q.push({ dr, dc });
                            }
                        }
                    }
                }
                answer.push_back(food);
            }
    sort(answer.begin(), answer.end(), less<>());
    if (answer.empty()) answer.push_back(-1);
    return answer;
}
#endif