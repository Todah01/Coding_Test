#if 0
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <limits.h>

using namespace std;

int bfs(vector<string> maps, tuple<int, int> start, tuple<int, int> exit, int row, int col) {
    int start_r, start_c, exit_r, exit_c;
    tie(start_r, start_c) = start;
    tie(exit_r, exit_c) = exit;

    vector<vector<int>> visited(row, vector<int>(col, INT_MAX));
    visited[start_r][start_c] = 0;

    queue<tuple<int, int, int>> q;
    q.emplace(start_r, start_c, visited[start_r][start_c]);

    vector<vector<int>> dir = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} };

    while (!q.empty()) {
        int cr, cc, cvc;
        tie(cr, cc, cvc) = q.front();
        q.pop();

        if (cr == exit_r && cc == exit_c)
            return cvc;

        for (auto iter : dir) {
            int dr = cr + iter[0], dc = cc + iter[1], dvc = cvc + 1;
            if (dr >= 0 && dr < row && dc >= 0 && dc < col && maps[dr][dc] != 'X' && dvc < visited[dr][dc]) {
                visited[dr][dc] = dvc;
                q.emplace(dr, dc, dvc);
            }
        }
    }

    return -1;
}

int solution(vector<string> maps) {
    int row = maps.size(), col = maps[0].length();
    tuple<int, int> start(0, 0), lever(0, 0), exit(0, 0);
    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++) {
            if (maps[r][c] == 'S') {
                get<0>(start) = r;
                get<1>(start) = c;
            }
            else if (maps[r][c] == 'L') {
                get<0>(lever) = r;
                get<1>(lever) = c;
            }
            else if (maps[r][c] == 'E') {
                get<0>(exit) = r;
                get<1>(exit) = c;
            }
        }

    int start_to_lever = bfs(maps, start, lever, row, col);
    int lever_to_exit = bfs(maps, lever, exit, row, col);

    if (start_to_lever != -1 && lever_to_exit != -1) return start_to_lever + lever_to_exit;
    else return -1;
}
#endif