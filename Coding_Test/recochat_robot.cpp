#if 0
#include <string>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

tuple<int, int> move_until_wall_or_hole(int r, int c, int row, int col, int diff_r, int diff_c, vector<string> temp_map) {
    while (0 <= row + diff_r && row + diff_r < r && 0 <= col + diff_c && col + diff_c < c
        && temp_map[row + diff_r][col + diff_c] != 'D') {
        row += diff_r;
        col += diff_c;
    }

    return make_tuple(row, col);
}

int solution(vector<string> board) {
    int r = board.size(), c = board[0].length();
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    vector<int> dr = { 1, -1, 0, 0 }, dc = { 0, 0, 1, -1 };

    int robot_row = -1, robot_col = -1;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            if (board[i][j] == 'R') {
                robot_row = i;
                robot_col = j;
            }
        }

    queue<tuple<int, int, int>> Q;
    Q.push(make_tuple(robot_row, robot_col, 0));

    while (!Q.empty()) {
        int robot_row, robot_col, lean_cnt;
        tie(robot_row, robot_col, lean_cnt) = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int new_robot_row, new_robot_col;
            tie(new_robot_row, new_robot_col) = move_until_wall_or_hole(r, c, robot_row, robot_col, dr[i], dc[i], board);
            if (board[new_robot_row][new_robot_col] == 'G')
                return lean_cnt + 1;

            if (!visited[new_robot_row][new_robot_col]) {
                visited[new_robot_row][new_robot_col] = true;
                Q.push(make_tuple(new_robot_row, new_robot_col, lean_cnt + 1));
            }
        }
    }

    return -1;
}
#endif

#if 0
#include <string>
#include <vector>
#include<queue>
#include<tuple>
#define MAX 100
#define INF 999999999
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int N, M;
int visit[MAX][MAX];
pair<int, int> slide(vector<string> g, pair<int, int> cur, int idx) {
    int x = cur.first, y = cur.second;
    while ((0 <= x && x < N && 0 <= y && y < M && g[x][y] != 'D')) {
        x += dx[idx]; y += dy[idx];
    }
    return { x - dx[idx], y - dy[idx] };
}
void bfs(vector<string> board, pair<int, int> start) {
    int a = start.first, b = start.second;
    queue<pair<int, int>> q;
    q.push({ a,b });
    visit[a][b] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i(0);i < 4;i++) {
            auto next = slide(board, { x,y }, i);
            int nx = next.first, ny = next.second;
            if (visit[nx][ny] != INF) continue;
            visit[nx][ny] = visit[x][y] + 1;
            q.push({ nx,ny });
        }
    }

}
int solution(vector<string> board) {
    N = board.size();
    M = board[0].length();
    pair<int, int> start, end;
    for (int i(0);i < N;i++) {
        for (int j(0);j < M;j++) {
            if (board[i][j] == 'R') start = { i,j };
            if (board[i][j] == 'G') end = { i,j };
            visit[i][j] = INF;
        }
    }
    bfs(board, start);

    return (visit[end.first][end.second] == INF) ? -1 : visit[end.first][end.second];
}
#endif