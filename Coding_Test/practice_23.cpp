#if 0
#include <vector>
#include <queue>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int visit[100][100];

int bfs(int a, int b, int m, int n, vector<vector<int>> painting)
{
    int color = painting[a][b];
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push({ a, b });
    visit[a][b] = 1;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n)
            {
                if (painting[nx][ny] == color && visit[nx][ny] == 0)
                {
                    visit[nx][ny] = 1;
                    q.push({ nx, ny });
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) visit[i][j] = 0;

    int cnt = 0;
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (picture[i][j] != 0 && visit[i][j] == 0)
            {
                int cnt = bfs(i, j, m, n, picture);
                if (cnt > max_size_of_one_area) max_size_of_one_area = cnt;
                number_of_area++;
            }
        }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return answer;
}
#endif